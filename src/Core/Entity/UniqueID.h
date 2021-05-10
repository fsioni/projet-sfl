#ifndef __UNIQUE_ID_H__
#define __UNIQUE_ID_H__


/*! \class UniqueID
*   \brief Stock un ID unique, deux instances d'UniqueID ne peuvent avoir le même ID.
*/
class UniqueID {
protected:
   /*! \brief Id du prochain UniqueID initialisé.*/
   static int nextID;
public:
   /*! \brief Identifiant unique. */
   int id;

   /*! \brief Constructeur par défaut. */
   UniqueID();

   /*! \brief Fonction de test de regression.
   *
   *   Effectue une série de test pour vérifié que chaque
   *   fonctions fait ce qu'elle doit faire.
   */
   void Test() const;
};


#endif
