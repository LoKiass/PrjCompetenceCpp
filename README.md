# 🚗 Gestion de Véhicules (Projet d'Apprentissage OOP)

Ce projet est une application console en **C++** conçue pour démontrer la mise en pratique des piliers fondamentaux de la **Programmation Orientée Objet (POO)**. L'objectif est de gérer un parc de véhicules (Camions et Voitures Électriques) en optimisant la structure du code pour éviter la redondance.

## 🌟 Compétences et Notions Démontrées

### 1. Encapsulation

L'utilisation de classes (`Voiture`, `Moteur`, `Roue`) avec des attributs **privés** accessibles via des **getters** et **setters**. Cela garantit l'intégrité des données (ex: validation des numéros de série ou des dimensions de roues).

### 2. Composition

Un exemple fort de la relation *"possède un"* :

* Une `Voiture` possède un `Moteur`.
* Une `Voiture` possède un `std::vector` de `Roue`.
Cela permet une gestion granulaire de chaque composant du véhicule.

### 3. Héritage

Mise en place d'une hiérarchie de classes pour favoriser la réutilisation du code :

* **Classe Mère :** `Voiture` (contient la logique commune : série, marque, moteur, roues).
* **Classes Filles :** `Camion` (ajoute la capacité de charge) et `VoitureElec` (ajoute l'autonomie).

### 4. Gestion Dynamique de la Mémoire

Utilisation de **pointeurs** et de l'allocation dynamique avec `new`. Le projet démontre une gestion rigoureuse du cycle de vie des objets avec l'utilisation de `delete` pour libérer la mémoire sur le Tas (*Heap*) et éviter les fuites mémoire.

### 5. Modularité et Réutilisabilité (DRY - Don't Repeat Yourself)

Implémentation d'une fonction de saisie générique `saisirInformationVoiture(Voiture& tempVoiture, ...)`. Grâce à l'héritage, cette fonction peut traiter n'importe quel type dérivé de `Voiture`, évitant ainsi de dupliquer la logique de saisie pour chaque nouveau type de véhicule.

---

## 🛠️ Structure du Projet

* **Voiture.h** : Classe de base définissant les propriétés universelles.
* **Camion.h / VoitureElec.h** : Spécialisations des véhicules.
* **Moteur.h / Roue.h** : Classes composants.
* **PrjCompetenceCpp.cpp** : Point d'entrée gérant les vecteurs de pointeurs et l'interaction utilisateur.

---

## 🚀 Prochaine Étape : Le Polymorphisme

La structure actuelle utilise des vecteurs séparés pour chaque type (`vector<Camion*>` et `vector<VoitureElec*>`).

**La prochaine évolution majeure de ce projet sera l'introduction du Polymorphisme :**

* Utilisation d'un vecteur unique `std::vector<Voiture*>` capable de stocker tous les types de véhicules.
* Utilisation de **méthodes virtuelles** (`virtual`) pour permettre un affichage unifié via une seule fonction `afficher()`.
* Utilisation de **destructeurs virtuels** pour sécuriser la libération de la mémoire des classes dérivées.

---

## ⚙️ Installation et Compilation

1. Clonez le dépôt.
2. Assurez-vous d'avoir un compilateur C++ (GCC/Clang/MSVC).
3. Compilez tous les fichiers `.cpp` :
```bash
g++ PrjCompetenceCpp.cpp Voiture.cpp Moteur.cpp Roue.cpp -o GestionVehicule

```

4. Lancez l'exécutable :
```bash
./GestionVehicule

```


---

*Projet réalisé dans le cadre d'un approfondissement des concepts de génie logiciel.*

---