#include "Operand.hpp"
#include "Factory.hpp"

Factory::Factory(void)
{
	_f[Int8] = &Factory::createInt8;
	_f[Int16] = &Factory::createInt16;
	_f[Int32] = &Factory::createInt32;
	_f[Float] = &Factory::createFloat;
	_f[Double] = &Factory::createDouble;
}

Factory::Factory(Factory const &cp) { *this = cp; }
Factory::~Factory(void) {}
Factory &Factory::operator=(Factory const &) { return *this; }

IOperand const *Factory::createOperand(eOperandType type, std::string const &value) const
{
	return ((this->*_f.at(type))(value));
}

IOperand const *Factory::createInt8(std::string const &value) const
{
	return (new Operand<int8_t>(value, 0, Int8));
}

IOperand const *Factory::createInt16(std::string const &value) const
{
	return (new Operand<int16_t>(value, 0, Int16));
}

IOperand const *Factory::createInt32(std::string const &value) const
{
	return (new Operand<int32_t>(value, 0, Int32));
}

IOperand const *Factory::createFloat(std::string const &value) const
{
	return (new Operand<float>(value, 4, Float));
}

IOperand const *Factory::createDouble(std::string const &value) const
{
	return (new Operand<double>(value, 7, Double));
}
