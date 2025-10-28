#include "Rele.hpp"
#include <Arduino.h>

// --- Construtor ---

Rele::Rele(uint8_t pin) {
	_pin_rele = pin;
	_estado_rele = false;
	_temporizador = false;
	_tempo_inicio = 0;
	_tempo_duracao = 0;

	pinMode(_pin_rele, OUTPUT);
	Off();
}


// --- Métodos de Ação ---

void Rele::On() {
	_estado_rele = true;
	digitalWrite(_pin_rele, HIGH);
}

void Rele::Off() {
	_estado_rele = false;
	_temporizador = false;
	digitalWrite(_pin_rele, LOW);
}

void Rele::Timer(uint8_t tempo_m) {
	if(_temporizador || tempo_m == 0) return;
	if(tempo_m > 180) tempo_m = 180;
	
	_tempo_inicio = millis();
	_tempo_duracao = (uint32_t)tempo_m * 60000UL;
	_temporizador = true;

	On();
}

void Rele::Update() {
	if (!_temporizador) return;
	if (millis() - _tempo_inicio >= _tempo_duracao) {
		Off();
	}
}
