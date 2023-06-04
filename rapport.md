### Ahmed Soussi, Enzo Greneche

# Rapport : Shooting Odissey

---
## Sommaire

### Introduction:
1. #### Objectifs du projet
### Conception du jeu:
1. #### Présentation du jeu
2. #### Conception de l'interface graphique
### Implémentation:
1. #### Organisation du code source
2. #### Développement des fonctionnalités principales
3. #### Gestion des interactions utilisateur
4. #### Gestion des événements graphiques
### Documentation technique:
1. #### Guide d'installation
2. #### Guide d'utilisation
3. #### Documentation du code source
### Conclusion:
1. #### Bilan du projet
2. #### Perspectives d'amélioration
3. #### Remerciements

---
## Introduction

### Objectifs du projet

L'objectif de ce projet est de développer une application graphique d'un jeu d'avion de type **Shoot'em up** (descendez-les tous)<br>
en temps réel et donc en gérant le taux de rafraîchissement de l'écran **F.P.S.** (Frames per second).<br>

---
## Conception du jeu

### Présentation du jeu

Le jeu est en 2d et se déroule dans l'espace. Le joueur contrôle un vaisseau spatial qui peut se déplacer dans toutes les directions.<br>
Il doit éviter ennemis et leurs tirs tout en les détruisant.<br>
Le jeu se termine lorsque le joueur n'a plus de vie ou lorsque le joueur a détruit tous les ennemis.<br>

### Conception de l'interface graphique

L'interface graphique est composée de plusieurs éléments :<br>
- Un fond d'écran qui représente l'espace et qui défile de bas en haut.<br>
- Un vaisseau spatial qui peut se déplacer dans toutes les directions.<br>
- Des ennemis qui apparaissent selon un fichier en haut de l'écran et qui se déplacent de haut en bas.<br>
- Des tirs qui sont lancés par le vaisseau et les ennemis.<br>

---
## Implémentation

### Organisation du code source

Pour ce projet, nous avons utilisé des fichiers de type '.h' pour déclarer et documenter des fonctions et des structures dans un dossier include<br>
et des fichiers de type '.c' pour implémenter les fonctions et les structures dans un dossier src.<br>
On a également utilisé un dossier data pour stocker les images et les sons utilisés dans le jeu.<br>

### Développement des fonctionnalités principales

### Gestion des interactions utilisateur

### Gestion des événements graphiques

---
## Documentation technique

### Guide d'installation

Pour installer le jeu, il faut d'abord cloner le dépôt git sur votre machine en utilisant la commande suivante :<br>
```bash
git clone https://github.com/ahmedSOUSSI21/shootingOdyssey.git
```
Ensuite, il faut compiler le code source en utilisant la commande suivante :<br>
```bash
make
```
Et enfin, il faut exécuter le fichier exécutable en utilisant la commande suivante :<br>
```bash
./main
```

### Guide d'utilisation

Pour jouer, il faut utiliser les touches suivantes :<br>
- **Z** pour se déplacer vers le haut.<br>
- **Q** pour se déplacer vers la gauche.<br>
- **S** pour se déplacer vers le bas.<br>
- **D** pour se déplacer vers la droite.<br>
- **Espace** pour tirer.<br>
- **Echap** pour mettre le jeu en pause.<br>

### Documentation du code source

La documentation du code source est disponible en ouvrant le fichier **doc.html** à la source du projet avec un navigateur web.<br>

---
## Conclusion

### Bilan du projet

Pour conclure, ce projet nous a permis de mettre en pratique les connaissances acquises en cours de programmation en C.<br>

### Perspectives d'amélioration

Pour améliorer le jeu, on peut ajouter les fonctionnalités suivantes :<br>
- Ajouter un Boss à la fin du niveau
- Ajouter des bonus
- Ajouter des niveaux

### Remerciements

Nous tenons à remercier notre professeur de programmation en C, M. Borie, pour son aide et ses conseils.<br>

---