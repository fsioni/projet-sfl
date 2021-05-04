#include "CollisionLayer.h"

#include "../tmxParsing.h"
#include <iostream>
#include <assert.h>
#include <memory>

CollisionLayer::CollisionLayer()
{
}

CollisionLayer::CollisionLayer(const std::string &objectgroupTagCollision)
{
    int count = countTag(objectgroupTagCollision, "object");
    std::string strObject;
    for (int i = 0; i < count; i++)
    {
        strObject = getInsideTag(objectgroupTagCollision, "object", i);
        CollisionBox cb(strObject);
        collisionBoxes.push_back(cb);
    }
}

CollisionLayer::~CollisionLayer()
{
    collisionBoxes.clear();
    //collisionBoxesEntity.clear();
}

void CollisionLayer::AddCollisionBox(const CollisionBox &newColBox)
{
    collisionBoxes.push_back(newColBox);
}

void CollisionLayer::AddCollisionBoxEntity(int id, CollisionBox* newColBox){
    collisionBoxesEntity[id] = newColBox;
}

void CollisionLayer::DisplayTXT() const
{
    for (long unsigned int i = 0; i < collisionBoxes.size(); i++)
    {
        std::cout << "Id : " << collisionBoxes[i].GetId() << std::endl;
        std::cout << "X : " << collisionBoxes[i].GetX() << std::endl;
        std::cout << "Y : " << collisionBoxes[i].GetY() << std::endl;
        std::cout << "W : " << collisionBoxes[i].GetWidth() << std::endl;
        std::cout << "H : " << collisionBoxes[i].GetHeight() << std::endl;
        std::cout << std::endl;
    }
}

std::vector<CollisionBox> CollisionLayer::GetCollisionBoxes() const
{
    return collisionBoxes;
}

std::map<int, CollisionBox*> CollisionLayer::GetCollisionBoxesEntity() 
{
    return collisionBoxesEntity;
}

bool CollisionLayer::CollisionBoxEntityExist(int id){
    return collisionBoxesEntity.find(id) != collisionBoxesEntity.end();
}

void CollisionLayer::DeleteACollisionBoxEntity(int id){
    // Si la clé existe on supprime la valeur
    if(CollisionBoxEntityExist(id))
        collisionBoxesEntity.erase(id);
}


void CollisionLayer::Test() const{
    std::cout << "===== Class CollisionLayer =====" << std::endl;

    CollisionLayer colLayer1;
    std::cout << "Constructeur CollisionLayer() : ";
    assert(colLayer1.collisionBoxes.empty());
    assert(colLayer1.collisionBoxesEntity.empty());
    std::cout << "ok" << std::endl;

    std::string strCollision = 
        std::string("<object id=\"14\" x=\"770\" y=\"926\" width=\"64\" height=\"64\"/>\n")+
        std::string("<object id=\"162\" x=\"833\" y=\"992\" width=\"64\" height=\"64\"/>\n")+
        std::string("<object id=\"154\" x=\"608\" y=\"928\" width=\"64\" height=\"64\"/>\n")+
        std::string("<object id=\"155\" x=\"544\" y=\"832\" width=\"64\" height=\"64\"/>\n")+
        std::string("<object id=\"156\" x=\"641\" y=\"768\" width=\"64\" height=\"64\"/>\n");

    CollisionLayer colLayer2(strCollision);
    std::cout << "Constructeur CollisionLayer"<<
                 "(const std::string &objectgroupTagCollision) : ";
    assert(colLayer2.collisionBoxes.size()==5);
    assert(colLayer2.collisionBoxes[0].GetX()==int(770));
    assert(colLayer2.collisionBoxes[1].GetX()==int(833));
    assert(colLayer2.collisionBoxes[2].GetX()==int(608));
    assert(colLayer2.collisionBoxes[3].GetX()==int(544));
    assert(colLayer2.collisionBoxes[4].GetX()==int(641));
    assert(colLayer2.collisionBoxesEntity.empty());
    std::cout << "ok" << std::endl;

    std::cout << "AddCollisionBox(const CollisionBox &newColBox)"<<
                " et GetCollisionBoxes() : ";
    colLayer1.AddCollisionBox(CollisionBox(1, 2, 3, 4));
    assert(colLayer1.GetCollisionBoxes().size()==1);
    assert(colLayer1.GetCollisionBoxes()[0].GetX()==1);
    assert(colLayer1.GetCollisionBoxes()[0].GetY()==2);
    assert(colLayer1.GetCollisionBoxes()[0].GetWidth()==3);
    assert(colLayer1.GetCollisionBoxes()[0].GetHeight()==4);
    std::cout << "ok" << std::endl;

    std::cout << "AddCollisionBoxEntity(int id, const CollisionBox &newColBox)"<<
                " et GetCollisionBoxesEntity() : ";
    colLayer1.AddCollisionBoxEntity(23, new CollisionBox(11, 21, 31, 41));
    assert(colLayer1.GetCollisionBoxesEntity().size()==1);
    assert(colLayer1.GetCollisionBoxesEntity()[23]->GetX()==11);
    assert(colLayer1.GetCollisionBoxesEntity()[23]->GetY()==21);
    assert(colLayer1.GetCollisionBoxesEntity()[23]->GetWidth()==31);
    assert(colLayer1.GetCollisionBoxesEntity()[23]->GetHeight()==41);
    std::cout << "ok" << std::endl;

    std::cout << "CollisionBoxEntityExist(int id) : ";
    assert(!colLayer1.CollisionBoxEntityExist(12));
    assert(colLayer1.CollisionBoxEntityExist(23));
    std::cout << "ok" << std::endl;

    std::cout << "DeleteACollisionBoxEntity(int id) : ";
    colLayer1.DeleteACollisionBoxEntity(12);
    assert(colLayer1.GetCollisionBoxesEntity().size()==1);
    colLayer1.DeleteACollisionBoxEntity(23);
    assert(colLayer1.GetCollisionBoxesEntity().size()==0);
    std::cout << "ok" << std::endl;

    std::cout << std::endl << std::endl;

}
