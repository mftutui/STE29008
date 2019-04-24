#ifndef GPIO_H
#define GPIO_H

class GPIO {
public:
	enum PortDirection_t {
		INPUT = 0,
		OUTPUT = 1
	};

	GPIO(uint8_t id, PortDirection_t dir);
	~GPIO();

	bool get();
	void set(bool val = 1);
	void clear();
	void toggle();

private:
	uint8_t _bit;
	uint8_t _id;
};

#endif
