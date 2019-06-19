#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

int main() {
	// Seed random number generator
	srand(time(NULL));

	// Random numbers
	int rand_num;
	int num_times;

	// User input
	std::string input;
	int input_num = 0;

	// Round/score info
	bool exit_flag = false;
	int score = 0;
	int not_gullible = 0;

	do {
		rand_num = rand() % 100;
		num_times = rand() % 10 + 1;

		std::cout << "Enter any number except " << rand_num << ":" << std::endl;
		for(int i = 0; i < num_times; i++) {
			std::cin >> input;

			if(std::cin.fail()) {
				std::cerr << "Invalid input!" << std::endl;
				return 1;
			}

			input_num = std::stoi(input);

			// If the user inputs the random number, terminate
			if(input_num == rand_num) {
				exit_flag = true;
				break;
			} else {
				not_gullible++;
			}
		}

		// Only increase score if the user completed the round
		if(!exit_flag) {
			score++;
		}
	} while(!exit_flag);

	std::cout << "You scored " << score << " points and entered " << not_gullible << " valid numbers." << std::endl;

	return 0;
}