#include "Main.h"

int main()
{
    //initalisation des frame de la fenétre
    window.setVerticalSyncEnabled(true);
    font.loadFromFile("res/Kanit-Bold.ttf");
    creatTexts(font, text_vie, player.get_pv(), text_scor, text_gameOver, text_resultat);
    
    // créer les obstacle
    creat_listeObstacle(listeObstacle, width, length, 15000, 20, 50);
    creat_listeObstacle(listeObstacle, width, length, 15000,200, 40);
    creat_listeObstacle(listeObstacle, width, length, 15000, 50, 20);



    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (window.isOpen())
    {
        // gestion des events
        while (window.pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed) window.close();

            //event mouvement
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) { movePlayer.up = true; }
                if (event.key.code == sf::Keyboard::Down) { movePlayer.down = true; }
                if (event.key.code == sf::Keyboard::Left) { movePlayer.left = true; }
                if (event.key.code == sf::Keyboard::Right) { movePlayer.right = true; }
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) { movePlayer.up = false; }
                if (event.key.code == sf::Keyboard::Down) { movePlayer.down = false; }
                if (event.key.code == sf::Keyboard::Left) { movePlayer.left = false; }
                if (event.key.code == sf::Keyboard::Right) { movePlayer.right = false; }
            }

        }




        //deplacer joueur
        if (player.get_pv() > 0) { player.movePlayer(movePlayer); }
        
        //boucle sur les obstacles
        for (auto it = listeObstacle.begin(); it != listeObstacle.end(); ) {
            //bouge l'obstacle
            it->moveObstacle();
            //remonte les obstacles qui sorte de l'écran
            if (it->get_shape().getPosition().y > length + it->get_shape().getRadius()) {
                it->changePosition(sf::Vector2f(it->get_shape().getPosition().x, -15000));
                std::cout << it->get_shape().getPosition().y << std::endl;
            }
            //tester si le player touche un obstacle
            if (player.get_pv() > 0 && is_colition2circle(player.get_shape().getGlobalBounds(), it->get_shape().getGlobalBounds())) {
                it = listeObstacle.erase(it); // Supprimer l'obstacle et obtenir le nouvel itérateur
                player.losePV();
                text_vie.setString("PV : " + std::to_string(player.get_pv()));
            }
            else { ++it; }
        }

        //mise a jour du scor
        if (player.get_pv() > 0) {
            score += 0.01;
            text_scor.setString("score : " + std::to_string(int(score)));
        }
        else {
            text_gameOver.setString(" Game Over ");
            text_resultat.setString("score finale : " + std::to_string(int(score)));
            text_gameOver.setPosition(400 - text_gameOver.getGlobalBounds().width / 2, 200);
            text_resultat.setPosition(400 - text_resultat.getGlobalBounds().width / 2, 300);
        }
        

        //affichage des sprites
        window.clear();
        for (auto& obstacle : listeObstacle) { obstacle.drawObstacle(window); }
        player.drawPlayer(window);
        window.draw(text_vie);
        window.draw(text_scor);
        window.draw(text_gameOver);
        window.draw(text_resultat);
        window.display();
    }
    return 0;
}


