#include <test_tcurses.h>

#include <ncurses.h>

void TestingApplication::init() {

	init_pair(100, COLOR_WHITE, COLOR_RED);
	init_pair(101, COLOR_WHITE, COLOR_GREEN);
	init_pair(102, COLOR_WHITE, COLOR_BLUE);

	// Menú principal (Absolute Layout)
	auto mainMenu = std::make_shared<TCurses::Menu>(2, 2, 20, 1);
	mainMenu->setBorder(std::make_shared<TCurses::LinedBorder>(1));
	mainMenu->addChild(std::make_shared<TCurses::MenuItem>("Test Text Align", 
		std::bind(&TestingApplication::itemTestTextAlign, this)));
	mainMenu->addChild(std::make_shared<TCurses::MenuItem>("Test Text Wrap", 
		std::bind(&TestingApplication::itemTestTextWrap, this)));
	mainMenu->addChild(std::make_shared<TCurses::MenuItem>("Test Emergents", 
		std::bind(&TestingApplication::itemTestEmergent, this)));

	mainMenu->addChild(std::make_shared<TCurses::MenuItem>("Quit", 
		std::bind(&TestingApplication::itemQuit, this)));

	// Ajusta el alto del menú a la cantidad de items
	mainMenu->setH(mainMenu->getChildren().size());

	screen->addChild(mainMenu);

	// Banco de pruebas (Absolute Layout)
	testBench = std::make_shared<TCurses::Frame>(24, 2, screen->getW() - 25, screen->getH() - 3);
	testBench->setBorder(std::make_shared<TCurses::LinedBorder>(1));
	screen->addChild(testBench);
}

void TestingApplication::itemTestTextAlign() {
	// Quita todos los hijos
	testBench->removeChildren();

	// Establece testBench a Vertical Layout
	testBench->setLayout(TCurses::LY_VERTICAL);

	auto frame = std::make_shared<TCurses::Frame>();
	frame->setLayout(TCurses::LY_HORIZONTAL);
	testBench->addChild(frame);

	auto label = std::make_shared<TCurses::Label>("Left - Top");
	label->setTextAlign(TCurses::HA_LEFT, TCurses::VA_TOP);
	label->setBGPair(100);
	frame->addChild(label);

	label = std::make_shared<TCurses::Label>("Center - Top");
	label->setTextAlign(TCurses::HA_CENTER, TCurses::VA_TOP);
	label->setBGPair(101);
	frame->addChild(label);

	label = std::make_shared<TCurses::Label>("Right - Top");
	label->setTextAlign(TCurses::HA_RIGHT, TCurses::VA_TOP);
	label->setBGPair(100);
	frame->addChild(label);

	frame = std::make_shared<TCurses::Frame>();
	frame->setLayout(TCurses::LY_HORIZONTAL);
	testBench->addChild(frame);

	label = std::make_shared<TCurses::Label>("Left - Center");
	label->setTextAlign(TCurses::HA_LEFT, TCurses::VA_CENTER);
	label->setBGPair(101);
	frame->addChild(label);

	label = std::make_shared<TCurses::Label>("Center - Center");
	label->setTextAlign(TCurses::HA_CENTER, TCurses::VA_CENTER);
	label->setBGPair(100);
	frame->addChild(label);

	label = std::make_shared<TCurses::Label>("Right - Center");
	label->setTextAlign(TCurses::HA_RIGHT, TCurses::VA_CENTER);
	label->setBGPair(101);
	frame->addChild(label);

	frame = std::make_shared<TCurses::Frame>();
	frame->setLayout(TCurses::LY_HORIZONTAL);
	testBench->addChild(frame);

	label = std::make_shared<TCurses::Label>("Left - Bottom");
	label->setTextAlign(TCurses::HA_LEFT, TCurses::VA_BOTTOM);
	label->setBGPair(100);
	frame->addChild(label);

	label = std::make_shared<TCurses::Label>("Center - Bottom");
	label->setTextAlign(TCurses::HA_CENTER, TCurses::VA_BOTTOM);
	label->setBGPair(101);
	frame->addChild(label);

	label = std::make_shared<TCurses::Label>("Right - Bottom");
	label->setTextAlign(TCurses::HA_RIGHT, TCurses::VA_BOTTOM);
	label->setBGPair(100);
	frame->addChild(label);
}

void TestingApplication::itemTestTextWrap() {
	testBench->removeChildren();
	testBench->setLayout(TCurses::LY_HORIZONTAL);

	auto label = std::make_shared<TCurses::Label>("No Wrap - No Wrap - No Wrap - No Wrap");
	label->setVTextAlign(TCurses::VA_CENTER);
	label->setWrap(TCurses::NO_WRAP);
	label->setBGPair(100);
	testBench->addChild(label);

	label = std::make_shared<TCurses::Label>("Wrap character - Wrap character - Wrap character - Wrap character - Wrap character - Wrap character");
	label->setVTextAlign(TCurses::VA_CENTER);
	label->setWrap(TCurses::WRAP_CHAR);
	label->setBGPair(101);
	testBench->addChild(label);

	label = std::make_shared<TCurses::Label>("Wrap Word Wrap Word Wrap Word Wrap Word Wrap Word Wrap Word Wrap Word");
	label->setVTextAlign(TCurses::VA_CENTER);
	label->setWrap(TCurses::WRAP_WORD);
	label->setBGPair(102);
	testBench->addChild(label);
}

void TestingApplication::itemTestEmergent() {
	testBench->removeChildren();

	emergentX = 5;
	emergentY = 3;

	showNewEmergent();
}

void TestingApplication::itemQuit() {
	this->quit();
}

void TestingApplication::showNewEmergent() {
	auto emergent = std::make_shared<TCurses::Emergent>(emergentX, emergentY, 20, 10);
	this->showEmergent(emergent);
	emergent->setLayout(TCurses::LY_VERTICAL);
	emergent->addChild(std::make_shared<TCurses::Label>("Test emergents"));
	auto menu = std::make_shared<TCurses::Menu>();
	menu->setMaxH(2);
	emergent->addChild(menu);
	menu->addChild(std::make_shared<TCurses::MenuItem>("New Emergent",
				std::bind(&TestingApplication::itemEmergentNew, this)));
	menu->addChild(std::make_shared<TCurses::MenuItem>("Close",
				std::bind(&TestingApplication::itemEmergentClose, this)));
	emergentX += 4;
	emergentY ++;
}

void TestingApplication::itemEmergentNew() {
	showNewEmergent();
}

void TestingApplication::itemEmergentClose() {
	this->disposeEmergent();
}

int main(int argc, char *argv[]) {
	TestingApplication app;
	app.run();
	return 0;
}
