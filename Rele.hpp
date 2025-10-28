#ifndef RELE_HPP
#define RELE_HPP

#include <arduino.h>

class Rele {

private:
	// --- Atributos ---
	uint8_t _pin_rele;
	bool _estado_rele;
	bool _temporizador;
	unsigned long _tempo_inicio;
	unsigned long _tempo_duracao;

public:
	// --- Construtor ---
	Rele(uint8_t pin);
	
	// --- Métodos Simples ---
	void On();
	void Off();
	void Timer(uint8_t tempo_m);
	void Update();

};

#endif
