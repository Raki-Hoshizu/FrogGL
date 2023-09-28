##### FrogGL README #####

Ce projet OpenGL contient :
* Une grenouille contrôlable par l'utilisateur
* Une grenouille non contrôlable avec un pattern de mouvement
* Un sol texturé avec de l'herbe
* Des cubes flottants à des positions aléatoire avec une animation de rouage appliquée sur une autre texture (opacité < 1.0f)
* Une caméra libre contrôlable par l'utilisateur
* Une caméra 3e personne liée à la grenouille contrôlable
* Un vertex Shader ainsi qu'un fragment Shader

### CONTROLE DE LA CAMERA ###

* Déplacements : ZQSD
	* Z : Avancer
	* S : Reculer
	* Q : Gauche
	* D : Droite
* Angle : Mouvement de la souris
* Zoom : Molette souris



### CONTROLE DE LA GRENOUILLE ###

* Déplacements : ZQSD
	* Z : Avancer
	* S : Reculer
	* Q : Pivoter vers la gauche
	* D : Pivoter vers la droite
	* Espace : Sauter



### CONTROLE GENERAL ###
* N : Changer de caméra (Libre / Grenouille)
* Echap : Quitter



### NOTES : ###
* Les cubes blanc / orange derrière la caméra ont été utilisé pour un entraînement à l'implémentation d'une lumière
		que je n'ai pas finie. Il n'y a donc pas de réelle lumière ici, simplement une variable dans le code qui va influer sur les couleurs
		et non les textures de l'environnement.
* Il est possible de faire sauter la grenouille tout en étant en caméra libre, avec la touche espace. Il n'est cependant pas possible
		de la déplacer
* Quand la grenouille saute, ses pattes arrières se détendent. Les pattes avant ne bougent pas.
* La grenouille ne peut pas sortir du carré d'herbe
* Vous pouvez changer la taille de départ de la fenêtre dans init.h

### INFOS ###

J'utilise la librairie glfw au lieu de glut.

Pour dessiner des formes j'ai implémenté une classe Mesh et des sous-classes Cube / Sphere / Plane avec des fonctions associées pour y mettre des textures, des couleurs.

Pour les matrices, je les créé pendant le dessin, les multiplie entre elles et les donne au Vertex Shader, qui s'occupe de la position.

La librairie GLM me sert à avoir des structures comme des vec3, des mat3 ou encore des mat4. Elle fournit aussi des opérations matricielles.

La librairie STB_IMAGE me permet de lire les images .jpg, .png etc afin d'en extraire les données pour texturer mes objets.
La librairie GLAD charge des pointeurs vers les fonctions d'OpenGL, pour en simplifier l'utilisation.