
#pragma warning( disable : 4996 ) 


#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
#include "G2D.h"


using namespace std;


// First, add a structure for the treasure
struct _Treasure
{
	string texture =
		"[        ]"
		"[GGGGGGGG]"
		"[GYYYYYG]"
		"[GYYYYYG]"
		"[GYYYYYG]"
		"[GYYYYYG]"
		"[GYYYYYG]"
		"[GGGGGGGG]";
	V2 Size;
	int IdTex;
	V2 Pos = V2(295, 509); // Position the treasure somewhere in the maze
};



// Add a structure for the "YOU WON" text, similar to the GameOver text
struct _YouWonText
{
	string texture =
		"[YYYY   YYYY   RRRRRRRRRRRRRR   RRR          RRR        RRR                  RRR       RRRRRRRRRRR    RRR           RRR ]"
		"[YYYY   YYYY  RR            RR  RRR          RRR        RRR                  RRR     RR           RR  RRRRR         RRR ]"
		"[ YYYY YYYY   RR            RR  RRR          RRR        RRR                  RRR     RR           RR  RRR RRR       RRR ]"
		"[  YYYYYYY    RR            RR  RRR          RRR        RRR                  RRR     RR           RR  RRR  RRR      RRR ]"
		"[   YYYYY     RR            RR  RRR          RRR        RRR                  RRR     RR           RR  RRR   RRR     RRR ]"
		"[    YYY      RR            RR  RRR          RRR        RRR       RRR        RRR     RR           RR  RRR    RRR    RRR ]"
		"[    YYY      RR            RR  RRR          RRR        RRR       RRR        RRR     RR           RR  RRR     RRR   RRR ]"
		"[    YYY      RR            RR  RRR          RRR         RRR      RRR       RRR      RR           RR  RRR      RRR  RRR ]"
		"[    YYY      RR            RR  RRR          RRR           RRR   RRR RRR   RRR       RR           RR  RRR       RRR RRR ]"
		"[    YYY      RR            RR  RRRRRRRRRRRRRRRR            RRR RRR   RRR RRR        RR           RR  RRR        RRRRRR ]"
		"[     Y         RRRRRRRRRRRRR                RRR              RRR       RRR            RRRRRRRRRRR    RRR         RRRRR ]"
		;
	V2 Size;
	int IdTex;
};

//STRUCTURE POUR GAME OVER
struct _GameOverText
{
	string texture =
		"[RRRRR  RRRRR  RRR  RRR  RRRRR     RRRRR  RRR   RRR  RRRRR  RRRRR]"
		"[RR     RR  RR RRRR RRR  RR        RR  R  RRR   RRR  RR     RR  RR]"
		"[RR GGG RRRRRR RR RR RR  RRRR      RR  R  RRR   RRR  RRRR   RRRRR ]"
		"[RR  RR RR  RR RR    RR  RR        RR  R   RRR RRR   RR     RR  RR]"
		"[RRRRR  RR  RR RR    RR  RRRRR     RRRRR    RRRRR    RRRRR  RR  RR]";
	V2 Size;
	int IdTex;
};


// Structure pour les fantômes
struct _Ghost
{
	string texture =
		"[        ]"
		"[  WWWW  ]"
		"[ WWWWWW ]"
		"[WWWWWWWW]"
		"[WWWBWBWW]"
		"[WWWWWWWW]"
		"[WWW  WWW]"
		"[WW WW WW]"
		"[W W  W W]";
	V2 Size;
	int IdTex;
	V2 Pos;
	V2 Direction;
	float Speed;

	_Ghost(V2 startPos, V2 dir, float sp) : Pos(startPos), Direction(dir), Speed(sp) {}
};




struct _Heros
{
	string texture =
		"[RRR  ]"
		"[RRWR ]"
		"[RRR  ]"
		"[YY   ]"
		"[YYY  ]"
		"[YY YG]"
		"[GG   ]"
		"[CC   ]"
		"[CC   ]"
		"[C C  ]"
		"[C C  ]";
	V2 Size;
	int IdTex;
	V2 Pos = V2(37, 95);
	V2 StartPos = V2(37, 95); // Mémoriser la position de départ pour les réinitialisations
};

struct _Key
{
	string texture =
		"[                      ]"
		"[     W W         WWWW ]"
		"[     W W        W    W]"
		"[   WWWWWWWWWWWWWW    W]"
		"[                W    W]"
		"[                 WWWW ]";


	V2 Size;
	int IdTex;
	V2 Pos = V2(740, 790);
};



// Structure pour les pièges
struct _Trap
{
	string texture =
		"[        ]"
		"[RRRRRRRR]"
		"[RYYYYYYYR]"
		"[RYYYYYYYR]"
		"[RYYYYYYYR]"
		"[RYYYYYYYR]"
		"[RYYYYYYYR]"
		"[RRRRRRRR]";
	V2 Size;
	int IdTex;
	V2 Pos;

	_Trap(V2 pos) : Pos(pos) {}
};



// Structure pour afficher les vies
struct _LifeIcon
{
	string texture =
		"[  RR  ]"
		"[ RRRR ]"
		"[RRRRRR]"
		"[RRRRRR]"
		"[ RRRR ]"
		"[  RR  ]";
	V2 Size;
	int IdTex;
};



struct GameData
{

	/*string Map =
		"MMMMMMMMMMMMMMM"
		"M M           M"
		"M M M MMM MMM M"
		"M   M       M M"
		"MMM M M MMM M M"
		"M   M M     M M"
		"M MMM MMM MMMMM"
		"M   M  M      M"
		"M M M  M M MM M"
		"M M M  M M M  M"
		"M M M MM M MMMM"
		"M M M    M    M"
		"M M M MMMMMMM M"
		"M M      M    M"
		"MMMMMMMMMMMMMMM";
		*/
	
	string Map =
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMM"
		"M MMM                M    MM"
		"M   M MMMM MMMMMMMMM   MM MM"
		"M M M M           MM M    MM"
		"M M MMM M MMM MMM  M MMM MMM"
		"M M     M       M MM       M"
		"M MMM M M M MMM M    MMMMM M"
		"MMM     M M     M MM M   M M"
		"MMM MMMMM MMM MMMMM  M M M M"
		"M       M  M      MM M M M M"
		"MMM M M M  M M MM    M MMM M"
		"MMM M M M  M M M  M MM     M"
		"M   M M M MM M MMMM MMM M MM"
		"M M   M M    M    M     M MM"
		"M M MMM M MMMMMMM MMM M M MM"
		"M M M M      M      M MMM  M"
		"M MMM MM MM MM M MM M   M MM"
		"M M       M M  M MM M M    M"
		"M M M MM MM MM M      MM M M"
		"M M M  M       MM MM MMM M M"
		"M MMMM MMM M M    MM   MMMMM"
		"M    M M M   MM MMMMM MM   M"
		"M MM   MMM M  M MM    MMMM M"
		"MMM  M     M MM MM MM    M M"
		"M MM M M M M    M  M  MM M M"
		"M    M M M MM  MMM MM  M M M"
		"MMM MM     MMMMM M MMMMM   M"
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMM";

		
	// Carte pour les pièges (T = piège, espace = pas de piège)
	string TrapMap =
		"                            "
		"      T                     "
		"                            "
		"                      T     "
		"                            "
		"                            "
		"           T                "
		"                            "
		"                      T     "
		"      T                     "
		"                            "
		"                            "
		"                            "
		"                T           "
		"         T                  "
		"                     T      "
		"                            "
		"   T                        "
		"                 T          "
		"                            "
		"          T                 "
		"                            "
		"                            "
		"                       T    "
		"      T                      "
		"                            "
		"                            "
		"                            ";




	// indique la présence d'un mur à la case (x,y)
	bool Mur(int x, int y) const { return Map[(28 - y - 1) * 28 + x] == 'M'; }  // les fonctions const ne modifient pas les données

	// indique la présence d'un piège à la case (x,y)
	bool EstPiege(int x, int y) const { return TrapMap[(28 - y - 1) * 28 + x] == 'T'; }


	int Lpix = 30;  // largeur en pixels des cases du labyrinthe

	_Heros Heros;   // data du héros
	_Key   Key;
	_LifeIcon LifeIcon; // Icône pour afficher les vies
	_Treasure Treasure;
	_YouWonText YouWonText;

	bool HasKey = false;     // Flag to indicate if player has collected the key
	bool GameWon = false;    // Flag to indicate if player has won the game

	vector<_Ghost> Ghosts;  // tableau de fantômes
	vector<_Trap> Traps;    // tableau de pièges

	bool GameOver = false;  // indique si le jeu est terminé
	_GameOverText GameOverText; // texture pour le texte GAME OVER

	int Lives = 3;          // nombre de vies du héros
	bool Invincible = false; // état d'invincibilité temporaire après avoir perdu une vie
	int InvincibleTimer = 0; // compteur pour l'état d'invincibilité
	const int InvincibleDuration = 100; // durée d'invincibilité (en cycles de logique)
	int gameOverTimer = 0;           // Timer for Game Over screen
	const int gameOverDuration = 150; // Duration to show Game Over (3 seconds at 50 calls per second)



	GameData() {

		// Initialiser les fantômes avec différentes positions et directions
		Ghosts.push_back(_Ghost(V2(150, 150), V2(1, 0), 1.0f));
		Ghosts.push_back(_Ghost(V2(200, 600), V2(0, -1), 1.1f));
		Ghosts.push_back(_Ghost(V2(389, 787), V2(0, 1), 1.2F));
		Ghosts.push_back(_Ghost(V2(519, 511), V2(-1, 0), 0.8f));
		Ghosts.push_back(_Ghost(V2(509, 367), V2(1, 1), 0.9F));

		// Initialiser les pièges à partir de la TrapMap
		for (int x = 0; x < 28; x++) {
			for (int y = 0; y < 28; y++) {
				if (EstPiege(x, y)) {
					Traps.push_back(_Trap(V2(x * Lpix, y * Lpix)));
				}
			}
		}

	}

};


// Add this function to reset the game state
void ResetGame(GameData& G)
{
	// Reset player position
	G.Heros.Pos = G.Heros.StartPos;

	// Reset game state
	G.Lives = 3;
	G.HasKey = false;
	G.GameOver = false;
	G.GameWon = false;
	G.Invincible = false;
	G.InvincibleTimer = 0;
	G.gameOverTimer = 0;

	// Reset ghost positions
	G.Ghosts[0].Pos = V2(150, 150);
	G.Ghosts[1].Pos = V2(200, 600);
	G.Ghosts[2].Pos = V2(389, 787);
	G.Ghosts[3].Pos = V2(519, 511);
	G.Ghosts[4].Pos = V2(509, 367);

	// Reset ghost directions
	G.Ghosts[0].Direction = V2(1, 0);
	G.Ghosts[1].Direction = V2(0, -1);
	G.Ghosts[2].Direction = V2(0, 1);
	G.Ghosts[3].Direction = V2(-1, 0);
	G.Ghosts[4].Direction = V2(1, 1);

	cout << "Game Reset! New game starting..." << endl;
}


void Render(const GameData& G)
{
	G2D::clearScreen(Color::Black);

	// Afficher le labyrinthe
	for (int x = 0; x < 28; x++)
		for (int y = 0; y < 28; y++)
		{
			int xx = x * G.Lpix;
			int yy = y * G.Lpix;
			if (G.Mur(x, y))
				G2D::drawRectangle(V2(xx, yy), V2(G.Lpix, G.Lpix), Color::Blue, true);
		}

	// Afficher les pièges
	for (const auto& trap : G.Traps)
	{
		G2D::drawRectWithTexture(trap.IdTex, trap.Pos, trap.Size);
	}

	// Afficher le héros avec boite englobante (clignotement si invincible)
	if (!G.Invincible || (G.InvincibleTimer % 10 < 5)) {
		G2D::drawRectangle(G.Heros.Pos, G.Heros.Size, Color::Red);
		G2D::drawRectWithTexture(G.Heros.IdTex, G.Heros.Pos, G.Heros.Size);
	}


	// Render the treasure
	G2D::drawRectWithTexture(G.Treasure.IdTex, G.Treasure.Pos, G.Treasure.Size);

	// Only render the key if player hasn't collected it yet
	if (!G.HasKey) {
		G2D::drawRectWithTexture(G.Key.IdTex, G.Key.Pos, G.Key.Size);
	}


	// Then modify the key rendering code:
	if (!G.HasKey) {
		// If not collected, draw at original position
		G2D::drawRectWithTexture(G.Key.IdTex, G.Key.Pos, G.Key.Size);
	}
	else {
		// If collected, draw near the hero (e.g., slightly above)
		V2 keyFollowPos = G.Heros.Pos + V2(0, -20); // Adjust offset as needed
		G2D::drawRectWithTexture(G.Key.IdTex, keyFollowPos, G.Key.Size * 0.7); // Maybe smaller
	}

	// Afficher la clef
	G2D::drawRectWithTexture(G.Key.IdTex, G.Key.Pos, G.Key.Size);

	// Afficher les fantômes
	for (const auto& ghost : G.Ghosts)
	{
		G2D::drawRectWithTexture(ghost.IdTex, ghost.Pos, ghost.Size);
	}

	// Afficher les vies restantes
	for (int i = 0; i < G.Lives; i++) {
		G2D::drawRectWithTexture(G.LifeIcon.IdTex, V2(20 + i * 30, 20), G.LifeIcon.Size);
	}

	// Afficher le message Game Over si le jeu est terminé
	if (G.GameOver)
	{
		// Calculer la position centrale pour le texte
		int centerX = (28 * G.Lpix) / 2 - G.GameOverText.Size.x / 2;
		int centerY = (28 * G.Lpix) / 2 - G.GameOverText.Size.y / 2;

		// Afficher le texte GAME OVER avec sa texture
		G2D::drawRectWithTexture(G.GameOverText.IdTex, V2(centerX, centerY), G.GameOverText.Size);
	}
	// If the game is won, display "YOU WON" text
	if (G.GameWon) {
		// Calculate the position for the text
		int centerX = (28 * G.Lpix) / 2 - G.YouWonText.Size.x / 2;
		int centerY = (28 * G.Lpix) / 2 - G.YouWonText.Size.y / 2;

		// Display the "YOU WON" text
		G2D::drawRectWithTexture(G.YouWonText.IdTex, V2(centerX, centerY), G.YouWonText.Size);
	}

	G2D::Show();
}



bool CollisionAvecMur(const GameData& G, const V2& pos)
{
	// Récupérer les dimensions du héros
	float heroWidth = G.Heros.Size.x;
	float heroHeight = G.Heros.Size.y;

	// Vérifier les 4 coins du rectangle du héros
	V2 coinHautGauche = pos;
	V2 coinHautDroit = V2(pos.x + heroWidth, pos.y);
	V2 coinBasGauche = V2(pos.x, pos.y + heroHeight);
	V2 coinBasDroit = V2(pos.x + heroWidth, pos.y + heroHeight);

	// Convertir les positions en indices de case
	int xHG = int(coinHautGauche.x / G.Lpix);
	int yHG = int(coinHautGauche.y / G.Lpix);

	int xHD = int(coinHautDroit.x / G.Lpix);
	int yHD = int(coinHautDroit.y / G.Lpix);

	int xBG = int(coinBasGauche.x / G.Lpix);
	int yBG = int(coinBasGauche.y / G.Lpix);

	int xBD = int(coinBasDroit.x / G.Lpix);
	int yBD = int(coinBasDroit.y / G.Lpix);

	// Vérifier que tous les coins sont dans les limites
	if (xHG < 0 || xHG >= 28 || yHG < 0 || yHG >= 28 ||
		xHD < 0 || xHD >= 28 || yHD < 0 || yHD >= 28 ||
		xBG < 0 || xBG >= 28 || yBG < 0 || yBG >= 28 ||
		xBD < 0 || xBD >= 28 || yBD < 0 || yBD >= 28)
		return true;

	// Vérifier qu'aucun coin n'est dans un mur
	return G.Mur(xHG, yHG) || G.Mur(xHD, yHD) || G.Mur(xBG, yBG) || G.Mur(xBD, yBD);
}


// Fonction pour vérifier la collision entre deux rectangles
bool CheckCollision(const V2& pos1, const V2& size1, const V2& pos2, const V2& size2)
{
	return (pos1.x < pos2.x + size2.x &&
		pos1.x + size1.x > pos2.x &&
		pos1.y < pos2.y + size2.y &&
		pos1.y + size1.y > pos2.y);
}


// Fonction pour vérifier si le héros est sur un piège
bool CheckTrapCollision(const GameData& G)
{
	// Centre du héros
	float heroCenterX = G.Heros.Pos.x + G.Heros.Size.x / 2;
	float heroCenterY = G.Heros.Pos.y + G.Heros.Size.y / 2;

	// Convertir en indices de case
	int caseX = int(heroCenterX / G.Lpix);
	int caseY = int(heroCenterY / G.Lpix);

	// Vérifier si c'est un piège
	return G.EstPiege(caseX, caseY);
}


// Fonction pour réinitialiser la position du héros
void ResetHeroPosition(GameData& G)
{
	G.Heros.Pos = G.Heros.StartPos;
	G.Invincible = true;
	G.InvincibleTimer = G.InvincibleDuration;
}

// Fonction pour gérer la perte d'une vie
void LoseLife(GameData& G)
{
	if (!G.Invincible) {
		G.Lives--;
		if (G.Lives <= 0) {
			G.GameOver = true;
		}
		else {
			ResetHeroPosition(G);
		}
	}
}

// Déclaration préalable de MoveGhosts pour résoudre le problème de référence
void MoveGhosts(GameData& G);


void Logic(GameData& G)
{
	
// Handle Game Over timer
	if (G.GameOver) {
		G.gameOverTimer++;
		if (G.gameOverTimer >= G.gameOverDuration) {
			ResetGame(G);
			return;
		}
		return;  // Don't process other game logic while in Game Over state
	}

	// Handle Game Won timer similar to Game Over timer
	if (G.GameWon) {
		G.gameOverTimer++;
		if (G.gameOverTimer >= G.gameOverDuration) {
			ResetGame(G);
			return;
		}
		return;  // Don't process other game logic while in Game Won state
	}
	// Gérer l'état d'invincibilité
	if (G.Invincible) {
		G.InvincibleTimer--;
		if (G.InvincibleTimer <= 0) {
			G.Invincible = false;
		}
	}


	V2 newPos = G.Heros.Pos;
	float step = 2.0f; // Vitesse de déplacement du héros

	if (G2D::isKeyPressed(Key::LEFT))  newPos.x -= step;
	if (G2D::isKeyPressed(Key::RIGHT)) newPos.x += step;
	if (G2D::isKeyPressed(Key::DOWN))  newPos.y -= step;
	if (G2D::isKeyPressed(Key::UP))    newPos.y += step;

	// On applique le mouvement seulement s'il n'y a pas de collision avec un mur
	if (!CollisionAvecMur(G, newPos))
		G.Heros.Pos = newPos;

	// Check collision with key
	if (!G.HasKey && CheckCollision(G.Heros.Pos, G.Heros.Size, G.Key.Pos, G.Key.Size)) {
		G.HasKey = true;
		cout << "Key collected!" << endl;
	}

	// Check collision with treasure
	if (G.HasKey && CheckCollision(G.Heros.Pos, G.Heros.Size, G.Treasure.Pos, G.Treasure.Size)) {
		G.GameWon = true;
		cout << "Treasure opened! You won!" << endl;
	}

	// Vérifier collision avec un piège
	if (CheckTrapCollision(G)) {
		LoseLife(G);
	}

	// Déplacer les fantômes
	MoveGhosts(G);

	cout << G.Heros.Pos << "   " << G.Heros.Size << " Vies:" << G.Lives << endl;
}

void AssetsInit(GameData& G)
{
	// Size passé en ref et texture en param
	G.Heros.IdTex = G2D::initTextureFromString(G.Heros.Size, G.Heros.texture);
	G.Heros.Size = G.Heros.Size * 2; // on peut zoomer la taille du sprite

	G.Key.IdTex = G2D::initTextureFromString(G.Key.Size, G.Key.texture);
	G.Key.Size = G.Key.Size * 1.5; // on peut zoomer la taille du sprite

	// Initialize treasure texture
	G.Treasure.IdTex = G2D::initTextureFromString(G.Treasure.Size, G.Treasure.texture);
	G.Treasure.Size = G.Treasure.Size * 2; // Zoom the treasure size

	// Initialize "YOU WON" texture
	G.YouWonText.IdTex = G2D::initTextureFromString(G.YouWonText.Size, G.YouWonText.texture);
	G.YouWonText.Size = G.YouWonText.Size * 3; // Zoom for visibility

	// Initialiser les textures des fantômes
	for (auto& ghost : G.Ghosts)
	{
		ghost.IdTex = G2D::initTextureFromString(ghost.Size, ghost.texture);
		ghost.Size = ghost.Size * 2; // Zoomer la taille des fantômes
	}

	// Initialiser les textures des pièges
	for (auto& trap : G.Traps)
	{
		trap.IdTex = G2D::initTextureFromString(trap.Size, trap.texture);
		trap.Size = G.Lpix * V2(1, 1); // Taille d'une case du labyrinthe
	}

	// Initialiser l'icône de vie
	G.LifeIcon.IdTex = G2D::initTextureFromString(G.LifeIcon.Size, G.LifeIcon.texture);
	G.LifeIcon.Size = G.LifeIcon.Size * 1.5; // Zoomer l'icône

	// Initialiser la texture GAME OVER
	G.GameOverText.IdTex = G2D::initTextureFromString(G.GameOverText.Size, G.GameOverText.texture);
	G.GameOverText.Size = G.GameOverText.Size * 3; // Zoom pour que ce soit bien visible
}

// Fonction pour déplacer les fantômes
void MoveGhosts(GameData& G)
{
	for (auto& ghost : G.Ghosts)
	{
		// Calculer la nouvelle position du fantôme
		V2 newPos = ghost.Pos + ghost.Direction * ghost.Speed;

		// Vérifier si la nouvelle position entraîne une collision avec un mur
		if (!CollisionAvecMur(G, newPos))
		{
			// Si pas de collision, mettre à jour la position
			ghost.Pos = newPos;
		}
		else
		{
			// Si collision, changer de direction aléatoirement
			// Générer un nombre aléatoire entre 0 et 3 pour choisir une direction
			int randDir = rand() % 4;
			switch (randDir)
			{
			case 0: ghost.Direction = V2(1, 0); break;  // droite
			case 1: ghost.Direction = V2(-1, 0); break; // gauche
			case 2: ghost.Direction = V2(0, 1); break;  // haut
			case 3: ghost.Direction = V2(0, -1); break; // bas
			}
		}

		// Vérifier collision avec le héros
		if (CheckCollision(G.Heros.Pos, G.Heros.Size, ghost.Pos, ghost.Size))
		{
			if (!G.Invincible) {
				LoseLife(G);
			}
		}
	}
}

int main(int argc, char* argv[])
{
	GameData G;

	G2D::initWindow(V2(G.Lpix * 28, G.Lpix * 28), V2(200, 200), string("Labyrinthe"));

	AssetsInit(G);

	int nbCalltoLogicPerSec = 50;

	G2D::Run(Logic, Render, G, nbCalltoLogicPerSec, true);
}