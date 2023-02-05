# R-TYPE

## Informations générales

Implementation of a multithreaded server and a graphical client for a game called R-Type, using an engine of our own design.

### Team

* Arthur Decaen (arthur.decaen@epitech.eu)
* Corentin Roy (corentin.roy@epitech.eu)
* Solène Lefeu (solene.lefeu@epitech.eu)
* Guillaume Vernizeau (guillaume.vernizeau@epitech.eu)
* Geoffrey Labruyère (geoffrey.labruyere@epitech.eu)

## Informations de developpement

### Norme des Commits

Exemples :

* **ADD:** good ECS
* **FIX:** no collision on same entity
* **UP:** remove useless print

| Name | Explanation                                                            |
| ---- | ---------------------------------------------------------------------- |
| ADD  | If you add files, features...                                          |
| FIX  | If you were working on a bug or any form of default that you corrected |
| DEL  | If you removed files, features...                                      |
| UP   | If you change something without adding any features or content         |

### CI/CD

* Build automatique sur les branches **main** et **dev**.
* Execution des tests unitaires Google Test sur les branches **main** et **dev**.
* Génération d'un coverage sur les branches **main** et **dev**.
* Génération automatique d'une documentation Doxygen sur les branches **main** et **dev** accessible [ici](arthurtakase.github.io/R-Type/).
* Envoi d'un message discord lors d'un push/merge sur toutes les branches.

### Doxygen

Pour une bonne génération de la documentation, veuillez à mettre des commentaires au dessus de vos fonctions selon le modèle suivante.

```cpp
/**
 * @brief Description du comportement de la fonction
 * 
 * @param parametre1 description du parametre
 * @param parametre2 description du parametre
 * 
 * @return explication sur la valeur de retour
 */
```

### Google Test

Toute fonciton doit posséder au minimum d'un test unitaire. Les tests fonctionnenent avec Google Test, la documentation est [ici](https://google.github.io/googletest/reference/testing.html).
