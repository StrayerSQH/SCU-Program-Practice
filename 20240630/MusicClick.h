#ifndef MUSICCLICK_H
#define MUSICCLICK_H

#include <SFML/Audio.hpp>
#include <string.h>

class MusicClick {
private:
	sf::Music musicClick;
	std::string musicClickFile;
public:
	MusicClick(const std::string& file);

	bool loadMusic();

	void play();

	void stop();

};

#endif // !MUSICCLICK_H
