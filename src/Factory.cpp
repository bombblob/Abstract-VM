#include "Factory.hpp"

Factory::Factory(void) {}
Factory::Factory(Factory const &cp) { *this = cp; }
Factory::~Factory(void) {}
Factory &Factory::operator=(Factory const &) { return *this; }

// typedef IOperand const *(std::string const &)const func;
// typedef int	(*t_fun_ptr)();

// typedef void* func;

// const func[] = {			// TODO: this, but later
// 		[0] = IOperand::createInt8,
// 		[1] = IOperand::createInt16,
// 		[2] = IOperand::createInt32,
// 		[3] = IOperand::createFloat,
// 		[4] = IOperand::createDouble,
// };

IOperand const *Factory::createOperand(eOperandType type, std::string const &value) const
{
	static_cast<void>(type);
	static_cast<void>(value);
	return (NULL);
}

IOperand const *Factory::createInt8(std::string const &value) const
{
	return (new Operand<int8_t>(std::stod(value), Int8));
}

IOperand const *Factory::createInt16(std::string const &value) const
{
	return (new Operand<int16_t>(std::stod(value), Int16));
}

IOperand const *Factory::createInt32(std::string const &value) const
{
	return (new Operand<int32_t>(std::stod(value), Int32));
}

IOperand const *Factory::createFloat(std::string const &value) const
{
	return (new Operand<float>(std::stod(value), Float));
}

IOperand const *Factory::createDouble(std::string const &value) const
{
	return (new Operand<double>(std::stod(value), Double));
}