# Get Next Line

*Parce que lire depuis un fd, c’est pas passionnant.*

## Description

Ce projet consiste à développer une fonction `get_next_line` en langage C qui permet de lire une ligne à la fois depuis un descripteur de fichier.

## Objectifs

- Implémenter la fonction `get_next_line` qui lit une ligne depuis un descripteur de fichier.
- Gérer les appels successifs pour lire l'intégralité du fichier texte référencé par le descripteur de fichier.
- Retourner la ligne lue suivie du caractère de fin de ligne `\n`.
- Compiler avec l'option `-D BUFFER_SIZE=n` où `n` est la taille du buffer pour les appels à la fonction `read()`.

## Partie Obligatoire

### Fonction

```
char *get_next_line(int fd);
```

## Fichiers de Rendu
- `get_next_line.h`
- `get_next_line.c`
- `get_next_line_utils.c`

## Paramètres
- `fd`: le descripteur de fichier depuis lequel lire.

## Valeur de Retour
- Le contenu de la ligne lue en cas de succès.
- `NULL` s'il n'y a rien d'autre à lire ou en cas d'erreur.

## Fonctions Externes Autorisées
- `read`, `malloc`, `free`

## Compilation
```
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=n get_next_line.c get_next_line_utils.c
```

## La macro BUFFER_SIZE
La macro BUFFER_SIZE spécifie la taille du buffer lors des appels à `read()`.

## Partie Bonus
- Gère plusieurs fichiers.

### Fichiers Bonus
- `get_next_line_bonus.c`
- `get_next_line_bonus.h`
- `get_next_line_utils_bonus.c`

### Remarques
- La fonction `lseek()` est interdite.
- Les variables globales sont interdites.
