#include "Fonction.h"



void creat_listeObstacle(vector<Obstacle>& listeObstacle, int& windowWidth, int& windowHeight, int distance, int nbrObstacle, int rayonne) {
	// Initialisation des générateurs de nombres aléatoires 
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// Génération des obstacles
	for (int i = 0; i < nbrObstacle; ++i) {
		Obstacle newObstacle = ( Obstacle(80/rayonne , rayonne, sf::Vector2f(0,-0)) );
		bool is_goodPosition = false;

		//verifi si la place est libre
		while (!is_goodPosition) {
			// Position aléatoire des obstacles
			float x = static_cast<float>((std::rand() % (windowWidth - rayonne * 2)) + rayonne);
			float y = static_cast<float>(std::rand() % distance);
			newObstacle.changePosition(sf::Vector2f(x, -y));

			//test les colisions
			bool isValid = true;
			for (Obstacle& obstacle : listeObstacle) {
				if (newObstacle.get_shape().getGlobalBounds().intersects(obstacle.get_shape().getGlobalBounds())) {
					isValid = false;
					break;
				}
			}
			if (isValid) { is_goodPosition = true; }
		}
		listeObstacle.push_back(newObstacle);
	}
}

bool is_colition2circle(sf::FloatRect&& player, sf::FloatRect&& obstacle) {
	float x = std::abs((player.getPosition().x + player.width/2) - (obstacle.getPosition().x + obstacle.width/2));
	float y = std::abs((player.getPosition().y + player.width/2) - (obstacle.getPosition().y + obstacle.width/2));
	float actualDistance = std::sqrt(std::pow(x, 2) + std::pow(y, 2));
	int distanceMini = player.width/2 + obstacle.width/2;
	if (actualDistance < distanceMini) {return true;}
	else { return false; }
}

void creatTexts(sf::Font& font, sf::Text& text_vie, int pv, sf::Text& text_scor, sf::Text& text_gameOver, sf::Text& text_resultat) {
	// choix de la police à utiliser
	text_vie.setFont(font); 
	text_scor.setFont(font); 
	text_gameOver.setFont(font);
	text_resultat.setFont(font);

	// choix de la chaîne de caractères à afficher
	text_vie.setString("PV : " + std::to_string(pv));
	text_scor.setString("score : 0");

	// choix de la taille des caractères
	text_vie.setCharacterSize(24); 
	text_scor.setCharacterSize(24);
	text_gameOver.setCharacterSize(48);
	text_resultat.setCharacterSize(36);

	//la position
	text_vie.setPosition(30, 10);
	text_scor.setPosition(620, 10);
}


