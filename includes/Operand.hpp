#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "IOperand.hpp"
#include <iomanip>	// TODO: this can go

template <typename T>
class Operand : public IOperand {

public:
	Operand(std::string const &string, eOperandType type)
		: _value(static_cast<T>(std::stod(string))), _type(type), _string(new std::string(string))
		{
			static const size_t size_arr[] = {
				4,
				6,
				11,
			};
			long long		n = std::stol(this->_string->c_str());

			std::cout << n << std::endl;
			// long double ldn = std::stold(this->_string->c_str());	// TODO: compare only integer part of doubles
			std::cout << static_cast<int32_t>(this->_value) << std::endl;
			if (this->_type < Int32 && (this->_value != n || this->_string->length() > size_arr[this->_type]))
			{
				std::cout << static_cast<int32_t>(this->_value) << " != " << n << std::endl;
				std::cout << this->_string->length() << " > " << size_arr[this->_type] << std::endl;
				throw OverflowException();
			}
		}

	Operand(void) : _value(0), _type(Int8), _string(new std::string(std::string(std::to_string(this->_value)))) { }

	Operand(Operand const &cp) { *this = cp; }

	~Operand(void)
		{
			delete this->_string;
		}

	Operand &operator=(Operand const &rhs)
		{
			this->_value = rhs._value;
			this->_type = rhs._type;
			delete this->_string;
			this->_string = new std::string(rhs._string->c_str());
			return *this;
		}

	virtual int					getPrecision(void) const
		{
			return (sizeof(_value));
		}

	virtual eOperandType		getType(void) const
		{
			return (this->_type);
		}

	virtual IOperand const *operator+(IOperand const &rhs) const
		{
			std::cout << "+ operator called on " << this->toString() << " and " << rhs.toString() << std::endl;

			return (NULL);
		}

	virtual IOperand const *operator-(IOperand const &rhs) const
		{
			static_cast<void>(rhs);
			std::cout << "- operator called" << std::endl;
			return (NULL);
		}

	virtual IOperand const *operator*(IOperand const &rhs) const
		{
			static_cast<void>(rhs);
			std::cout << "* operator called" << std::endl;
			return (NULL);
		}

	virtual IOperand const *operator/(IOperand const &rhs) const
		{
			static_cast<void>(rhs);
			std::cout << "/ operator called" << std::endl;
			return (NULL);
		}

	virtual IOperand const *operator%(IOperand const &rhs) const
		{
			static_cast<void>(rhs);
			std::cout << "% operator called" << std::endl;
			return (NULL);
		}

	virtual std::string const		&toString(void) const
		{
			return (*this->_string);
		}

	class OverflowException : public std::exception {
	public:
		OverflowException( void ) { }
		OverflowException( OverflowException const &cp ) { *this = cp; }
		~OverflowException( void ) throw() { }
		OverflowException &operator=( OverflowException const & ) { return *this; }
		virtual const char *what() const throw() { return ("Overflow"); }
	};

	class UnderflowException : public std::exception {
	public:
		UnderflowException( void ) { }
		UnderflowException( UnderflowException const &cp ) { *this = cp; }
		~UnderflowException( void ) throw() { }
		UnderflowException &operator=( UnderflowException const & ) { return *this; }
		virtual const char *what() const throw() { return ("Underflow"); }
	};

	class DivisionByZeroException : public std::exception {
	public:
		DivisionByZeroException( void ) { }
		DivisionByZeroException( DivisionByZeroException const &cp ) { *this = cp; }
		~DivisionByZeroException( void ) throw() { }
		DivisionByZeroException &operator=( DivisionByZeroException const & ) { return *this; }
		virtual const char *what() const throw() { return ("DivisionByZero"); }
	};

private:
	T _value;
	eOperandType _type;
	std::string *_string;
};

#endif
