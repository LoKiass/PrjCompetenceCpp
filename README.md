# 🏎️ Gestionnaire de Garage C++

Ce projet est une étude pratique des concepts de **Programmation Orientée Objet (POO)** en C++. L'objectif est de modéliser un système de gestion de véhicules en utilisant l'agrégation, l'héritage et le polymorphisme.

## 🛠️ Concepts Abordés

### 1. Agrégation ("A un")

Le véhicule n'est pas une entité monolithique. Il est composé d'objets distincts :

* **Moteur** : Gère la puissance et le type de carburant.
* **Roue** : Gère la taille et l'usure pneumatique.
* **Véhicule** : Agrège 1 moteur et 4 roues.

### 2. Héritage ("Est un")

Pour éviter la duplication de code, nous utilisons une classe de base `Vehicule` qui est ensuite spécialisée :

* `VoitureElectrique` : Spécificité sur l'autonomie et la batterie.
* `Camion` : Spécificité sur la capacité de charge et le tonnage.

### 3. Polymorphisme

Utilisation de **méthodes virtuelles** pour permettre un traitement générique. Le garage peut stocker une liste de `Vehicule*` et appeler `afficherInfos()` sans savoir s'il s'agit d'une Tesla ou d'un Renault Master au moment de la compilation.

---

## 📋 Énoncé du Projet

### Étape 1 : Les Composants (Agrégation)

Développer les classes `Moteur` et `Roue`. La classe `Vehicule` doit contenir un pointeur vers un `Moteur` et un tableau d'objets `Roue`.

> **Challenge :** Implémenter un destructeur dans `Vehicule` qui gère correctement la mémoire du moteur si celui-ci est alloué dynamiquement.

### Étape 2 : La Hiérarchie (Héritage)

Créer la classe `Vehicule` (abstraite ou non) et faire dériver `VoitureElectrique` et `Camion`.

* Le constructeur de la classe fille doit appeler le constructeur de la classe mère.

### Étape 3 : Le Garage (Polymorphisme)

Créer une classe `Garage` qui contient un `std::vector<Vehicule*>`.

* Ajouter une méthode `etatDesLieux()` qui parcourt le vecteur.
* Chaque véhicule doit répondre de manière spécifique via une fonction `virtual void emettreSon()`.

---

## 🚀 Installation et Compilation

```bash
# Cloner le dépôt
git clone https://github.com/votre-compte/garage-cpp.git

# Compiler le projet
g++ -o garage main.cpp Moteur.cpp Roue.cpp Vehicule.cpp -Wall

# Lancer l'application
./garage

```

---

## 📂 Structure du Code

* `/include` : Fichiers d'en-tête (.hpp)
* `/src` : Implémentation des classes (.cpp)
* `main.cpp` : Point d'entrée avec les tests unitaires.