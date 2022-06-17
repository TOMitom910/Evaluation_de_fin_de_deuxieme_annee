DROP DATABASE IF EXISTS GAMERS;
CREATE DATABASE IF NOT EXISTS GAMERS DEFAULT CHARSET = latin1 COLLATE = latin1_general_cs; 

DROP TABLE IF EXISTS joueur;
CREATE TABLE IF NOT EXISTS joueur(
   ID_Joueur INT NOT NULL AUTO_INCREMENT,
   Pseudo VARCHAR(50) NOT NULL,
   Genre VARCHAR(50) NOT NULL,
   PRIMARY KEY(ID_Joueur)
) ENGINE = innoDB DEFAULT CHARSET = latin1 COLLATE = latin1_general_cs;

DROP TABLE IF EXISTS jeux;
CREATE TABLE IF NOT EXISTS jeux(
   ID_Jeux INT NOT NULL AUTO_INCREMENT,
   Nom_Jeu VARCHAR(50) NOT NULL,
   Version_Jeu VARCHAR(50) NOT NULL,
   PRIMARY KEY(ID_Jeux)
)ENGINE = innoDB DEFAULT CHARSET = latin1 COLLATE = latin1_general_cs;

DROP TABLE IF EXISTS score;
CREATE TABLE IF NOT EXISTS score(
   ID_Score INT NOT NULL AUTO_INCREMENT,
   Score VARCHAR(50) NOT NULL,
   Date_Score DATE NOT NULL,
   ID_Joueur INT NOT NULL,
   ID_Jeux INT NOT NULL,
   PRIMARY KEY(ID_Score),
   FOREIGN KEY(ID_Joueur) REFERENCES Joueur(ID_Joueur),
   FOREIGN KEY(ID_Jeux) REFERENCES Jeux(ID_Jeux)
)ENGINE = innoDB DEFAULT CHARSET = latin1 COLLATE = latin1_general_cs;
