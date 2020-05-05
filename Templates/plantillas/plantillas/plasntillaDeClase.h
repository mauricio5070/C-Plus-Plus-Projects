#pragma once
#include <iostream>
using namespace std;
	template <class T>
	class Par{
	private:
		T primero;
		T segundo;
	public:
		Par(T primerValor, T segundoValor);
		void fijaElemento(int ubicacion, T valor);
		T obtenerElemento(int ubicacion);
	
	
	
	
	};
	//-------------------------------------------------generacion de la plantilla-----------------------------------

	//
	template<class T>
	inline  Par<T>::Par(T primerValor, T segundoValor)
	{
		primero = primerValor;
		segundo = segundoValor;
	}

	template<class T>
	void Par<T>::fijaElemento(int ubicacion, T valor)
	{

		if (ubicacion == 1) {
			primero = valor;
		}
		else {
		
			segundo = valor;
		}
	}

	template<class T>
	T Par<T>::obtenerElemento(int ubicacion)
	{
		if(ubicacion == 1) {
			return primero;
		}
		else {

			return segundo;
		}
	}
