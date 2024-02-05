#include <iostream>

#include <SFML/Network.hpp>

#include <Application.hpp>
#include <MainMenuActivity.hpp>
#include <AppConfig.hpp>


int main() {
	unsigned int seed = std::time(nullptr);
	std::cerr << "Seed: " << seed << std::endl;
	std::srand(seed);

	// AppConfig &config = AppConfig::getInstance();
	// sf::Vector2f windowSize = config.get<sf::Vector2f>(ConfigKey::WindowSize);
	// std::string windowTitle = config.get<std::string>(ConfigKey::AppName);

	// Application app(windowSize.x, windowSize.y, windowTitle);
	// Activity::Ptr launcher = std::make_unique<MainMenuActivity>();
	// app.addLauncher(std::move(launcher));
	// app.run();

	sf::TcpSocket socket;
	sf::Socket::Status status = socket.connect("127.0.0.1", 8080);
	std::cerr << (unsigned int)status << '\n';
	sf::Packet

	return 0;
}