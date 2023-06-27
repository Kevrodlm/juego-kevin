#pragma once
class room {
private:
	int type;
	bool roomFinish;
	char roomContent[9][13];
public:
	room(int type, std::string roomFile, bool doorUp, bool doorDown, bool doorLeft, bool doorRight) {
		std::ifstream roomText(roomFile);
		for (int j = 0; j < 9; j++) {
			for (int i = 0; i < 13; i++) {
				if (i == 0 || i == 12 || j == 0 || j == 8) {
					roomContent[j][i] = 'x';
				}
				else {
					roomText >> roomContent[j][i];
				}
			}
		}
		if (doorUp) { roomContent[4][0] = 'd'; }
		if (doorDown) { roomContent[4][12] = 'd'; }
		if (doorLeft) { roomContent[0][6] = 'd'; }
		if (doorRight) { roomContent[8][6] = 'd'; }
		this->type = type;
		roomFinish = 0;
	}
	void viewRoom() {
		for (int j = 0; j < 9; j++) {
			for (int i = 0; i < 13; i++) {
				std::cout << roomContent[j][i] << " ";
			}
			std::cout << std::endl;
		}
	}

};