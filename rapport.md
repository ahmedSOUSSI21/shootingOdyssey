### <p style="color: lightslategrey"><p style="color: lightblue">Ahmed Soussi, Enzo Greneche</p>

# Rapport : Shooting Odissey

## <p style="color: lightblue">Sommaire</p>

### <p style="color: lightslategrey">Introduction</p>
- #### Objectifs du projet
### <p style="color: lightslategrey">Conception du jeu</p>
- #### Présentation du jeu
- #### Conception de l'interface graphique
### <p style="color: lightslategrey">Implémentation</p>
- #### Organisation du code source
- #### Développement des fonctionnalités principales
- #### Gestion des interactions utilisateur
- #### Gestion des événements graphiques
### <p style="color: lightslategrey">Documentation technique</p>
- #### Guide d'installation
- #### Guide d'utilisation
- #### Documentation du code source
### <p style="color: lightslategrey">Conclusion</p>
- #### Bilan du projet
- #### Perspectives d'amélioration
- #### Remerciements

---
## <p style="color: lightblue">Introduction</p>

### <p style="color: lightslategrey">Objectifs du projet</p>

L'objectif de ce projet est de **développer une application graphique d'un jeu d'avion de type **Shoot'em up** (descendez-les tous)**<br>
en temps réel et donc en gérant le taux de rafraîchissement de l'écran **F.P.S.** (Frames per second).<br>

---
## <p style="color: lightblue">Conception du jeu</p>

### <p style="color: lightslategrey">Présentation du jeu</p>

Le jeu est en **2d** et se déroule dans **l'espace**. Le joueur contrôle un vaisseau spatial qui peut se déplacer dans **toutes les directions**.<br>
Il doit éviter ennemis et leurs tirs tout en les détruisant.<br>
Le jeu se termine lorsque le joueur n'a plus de vie ou lorsque le joueur a détruit tous les ennemis.<br>

### <p style="color: lightslategrey">Conception de l'interface graphique</p>

L'interface graphique est composée de plusieurs éléments :<br>
- Un **fond d'écran** qui représente l'espace et qui défile de bas en haut.<br>
- Un **vaisseau spatial** qui peut se déplacer dans toutes les directions.<br>
- Des **ennemis** qui apparaissent selon un fichier en haut de l'écran et qui se déplacent de haut en bas.<br>
- Des **tirs** qui sont lancés par le vaisseau et les ennemis.<br>

---
## <p style="color: lightblue">Implémentation</p>

### <p style="color: lightslategrey">Organisation du code source</p>

Pour ce projet, nous avons utilisé des fichiers de type '.h' pour déclarer et documenter des fonctions et des structures dans un dossier include<br>
et des fichiers de type '.c' pour implémenter les fonctions et les structures dans un dossier src.<br>
On a également utilisé un dossier data pour stocker les images et les sons utilisés dans le jeu.<br>

### <p style="color: lightslategrey">Développement des fonctionnalités principales</p>

- le création du vaisseau
- la création des ennemis
- les mouvements du vaisseau
- les mouvements des ennemis
- création des tirs
- mouvement des tirs avec des angles
- création d'animations (reload et explosion)
- gestion des collisions (vaisseau-ennemis, vaisseau-tirs, ennemis-tirs)
- creation menu et score

---
## <p style="color: lightblue">Documentation technique</p>

### <p style="color: lightslategrey">Guide d'installation

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

### <p style="color: lightslategrey">Guide d'utilisation

Pour jouer, il faut utiliser les touches suivantes :<br>
- **Z** pour se déplacer vers le haut.<br>
- **Q** pour se déplacer vers la gauche.<br>
- **S** pour se déplacer vers le bas.<br>
- **D** pour se déplacer vers la droite.<br>
- **Espace** pour tirer.<br>
- **Echap** pour mettre le jeu en pause.<br>

### <p style="color: lightslategrey">Documentation du code source

La documentation du code source est disponible en ouvrant le fichier [doc.html](doc.html) à la source du projet avec un navigateur web.<br>

---
## <p style="color: lightblue">Conclusion</p>

### <p style="color: lightslategrey">Bilan du projet

Pour conclure, ce projet nous a permis de mettre en pratique les connaissances acquises en cours de programmation en C.<br>
Autres competence acquises :<br>
- Utilisation de la libMLV pour la création d'une interface graphique et la gestion des événements.<br>

### <p style="color: lightslategrey">Perspectives d'amélioration

Pour améliorer le jeu, on peut ajouter les fonctionnalités suivantes :<br>
- Ajouter un Boss à la fin du niveau
- Ajouter des bonus
- Ajouter des niveaux

### <p style="color: lightslategrey">Remerciements

Nous tenons à remercier notre professeur de programmation en C, **M. Borie**, pour son aide et ses conseils.<br>

---