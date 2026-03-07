#include "long_number.h"

using pve::LongNumber;

LongNumber::LongNumber() {
	length = 1;
	numbers = new int[length];
	numbers[0] = 0;
	sign = 1;

}

LongNumber::LongNumber(int length, int sign) {
	this->length = length;
	this->sign = sign;
	numbers = new int[length]();
}

LongNumber::LongNumber(const char* const str) {
	if (str[0] == '-') {
		sign = -1;
	}
	else {
		sign = 1;
	}
	length = get_length(str);
	int ind = 0;
	if (sign == -1) {
		ind = 1;
	}
	numbers = new int[length];
	for (int i = 0;i < length;++i) {
		numbers[i] = str[ind+length-1-i]-'0';
	}
}

LongNumber::LongNumber(const LongNumber& x) {
	sign = x.sign;
	length = x.length;
	numbers = new int[length];
	for (int i = 0;i < length;++i) {
		numbers[i] = x.numbers[i];
	}
}

LongNumber::LongNumber(LongNumber&& x) {
	numbers = x.numbers;
	sign = x.sign;
	length = x.length;

	x.numbers = nullptr;
	x.length = 0;
}

LongNumber::~LongNumber() {
	if (numbers != nullptr) {
		delete[] numbers;
	}
}

LongNumber& LongNumber::operator = (const char* const str) {
	int start = 0;
	sign = 1;
	if (str[0] == '-') {
		sign = -1;
		start = 1;
	}
	delete[] numbers;
	length = get_length(str);
	numbers = new int[length];
	for (int i = 0;i < length;++i) {
		numbers[i] = str[start + length - 1 - i] - '0';
	}
	return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
	if (this == &x) {
		return *this;
	}
	delete[] numbers;
	sign = x.sign;
	length = x.length;
	numbers = new int[length];
	for (int i = 0;i < length;++i) {
		numbers[i] = x.numbers[i];
	}

	return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
	if (this == &x) {
		return *this;
	}

	delete[] numbers;
	length = x.length;
	sign = x.sign;
	numbers = x.numbers;
	x.numbers = nullptr;
	x.length = 0;

	return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {
	if (sign != x.sign) {
		return false;
	}
	if (length != x.length) {
		return false;
	}
	for (int i = 0;i < length;++i) {
		if (numbers[i] != x.numbers[i]) {
			return false;
		}
	}

	return true;
}

bool LongNumber::operator != (const LongNumber& x) const {
	return !(*this == x);
}

bool LongNumber::operator > (const LongNumber& x) const {
	if (sign > x.sign) {
		return true;
	}
	if (sign < x.sign) {
		return false;
	}
	if (sign == 1) {
		if (length > x.length) {
			return true;
		}
		if (length < x.length) {
			return false;
		}

		for (int i = length - 1;i >= 0;i-- ) {
			if (numbers[i] == x.numbers[i]) {
				continue;
			}
			if (numbers[i] > x.numbers[i]) {
				return true;
			}
			else {
				return false;
			}
		}
		return false;
	}
	else {
		if (length > x.length) {
			return false;
		}
		if (length < x.length) {
			return true;
		}

		for (int i = length - 1;i >= 0;i-- ) {
			if (numbers[i] == x.numbers[i]) {
				continue;
			}
			if (numbers[i] > x.numbers[i]) {
				return false;
			}
			else {
				return true;
			}
		}
		return false;
	}
	
}

bool LongNumber::operator < (const LongNumber& x) const {
	return x > *this;
}

bool LongNumber::operator >= (const LongNumber& x) const {
	return !(*this < x);
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	LongNumber result;
	if (sign != x.sign) {
		if (sign == 1) {
			return *this - (-x);
		}
		else {
			return x - (-*this);
		}
	}
	int maxlen;
	if (x.length > length) {
		maxlen = x.length;
	}
	else {
		maxlen = length;
	}
	delete[] result.numbers;
	result.sign = sign;
	result.length = maxlen + 1;
	result.numbers = new int[result.length];
	int cur = 0;
	for (int i = 0;i<result.length;++i) {
		int sum = cur;
		if (i < x.length) {
			sum += x.numbers[i];
		}
		if (i < length) {
			sum += numbers[i];
		}
		result.numbers[i] = sum % 10;
		cur = sum / 10;
	}
	
	while (result.length > 1 && result.numbers[result.length - 1] == 0) {
		result.length--;
	}
	return result;

}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	if (sign != x.sign) {
		return *this + (-x);
	}
	bool first = false;
	if (length > x.length) {
		first = true;
	}
	else if (length == x.length) {
		for (int i = length-1;i >=0;--i) {
			if (numbers[i] > x.numbers[i]) {
				first = true;
				break;
			}
			else if (numbers[i] < x.numbers[i]) {
				break;
			}
		}
	}
	LongNumber result;
	delete[] result.numbers;
	if (first) {
		result.sign = sign;
		result.length = length;
	}
	else {
		result.sign = -sign;
		result.length = x.length;
	}
	result.numbers = new int[result.length];
	int borrow = 0;
	if (first) {
		for (int i = 0;i < length;++i) {
			int cur = numbers[i] - borrow;
			if (i < x.length) {
				cur -= x.numbers[i];
			}
			if (cur < 0) {
				cur += 10;
				borrow = 1;
			}
			else {
				borrow = 0;
			}
			result.numbers[i] = cur;
		}
	}
	else {
		for (int i = 0;i < x.length;++i) {
			int cur = x.numbers[i] - borrow;
			if (i < length) {
				cur -= numbers[i];
			}
			if (cur < 0) {
				cur += 10;
				borrow = 1;
			}
			else {
				borrow = 0;
			}
			result.numbers[i] = cur;
		}

	}
	while (result.length > 1 && result.numbers[result.length - 1] == 0) {
		result.length--;
	}
	if (result.length == 1 && result.numbers[0] == 0) {
		result.sign = 1;
	}
	return result;
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	LongNumber result;
	delete[] result.numbers;
	result.length = length + x.length;
	result.sign = sign * x.sign;
	result.numbers = new int[result.length]();
	
	for (int i = 0;i < length;++i) {
		int carry = 0;
		for (int j = 0;j < x.length;++j) {
			int cur = carry + result.numbers[i + j] + numbers[i] * x.numbers[j];
			result.numbers[i + j] = cur % 10;
			carry = cur / 10;

		}
		if (carry > 0) {
			result.numbers[i + x.length] = carry;
		}
	}
	while (result.length > 1 && result.numbers[result.length - 1] == 0) {
		result.length--;
	}
	return result;
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
	if (x.length == 1 && x.numbers[0] == 0) {
		return LongNumber();
	}

	int result_sign = sign * x.sign;

	LongNumber dividend = abs();
	LongNumber divisor = x.abs();

	if (dividend < divisor) {
		return LongNumber();
	}

	if (dividend == divisor) {
		LongNumber result("1");
		result.sign = result_sign;
		return result;
	}

	LongNumber result;
	result.sign = result_sign;

	int* result_digits = new int[dividend.length]();
	int result_length = 0;

	LongNumber current;
	current.sign = 1;
	current.length = 1;
	current.numbers = new int[1]();
	current.numbers[0] = 0;

	for (int i = dividend.length - 1; i >= 0; i--) {
		LongNumber temp;
		delete[] temp.numbers;
		temp.length = current.length + 1;
		temp.numbers = new int[temp.length]();
		temp.sign = 1;

		for (int j = 0; j < current.length; j++) {
			temp.numbers[j + 1] = current.numbers[j];
		}

		temp.numbers[0] = dividend.numbers[i];

		while (temp.length > 1 && temp.numbers[temp.length - 1] == 0) {
			temp.length--;
		}

		delete[] current.numbers;

		current.length = temp.length;
		current.numbers = new int[current.length];
		for (int j = 0; j < current.length; j++) {
			current.numbers[j] = temp.numbers[j];
		}

		delete[] temp.numbers;

		int digit = 0;
		while (current >= divisor) {
			current = current - divisor;
			digit++;
		}

		result_digits[result_length] = digit;
		result_length++;
	}

	delete[] result.numbers;
	result.length = result_length;
	result.numbers = new int[result_length];

	for (int i = 0; i < result_length; i++) {
		result.numbers[i] = result_digits[result_length - 1 - i];
	}

	delete[] result_digits;
	delete[] current.numbers;

	while (result.length > 1 && result.numbers[result.length - 1] == 0) {
		result.length--;
	}

	return result;
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	if (x.length == 1 && x.numbers[0] == 0) {
		return LongNumber();
	}

	LongNumber div = *this / x;
	LongNumber result = *this - div * x;
	return result;
}

bool LongNumber::is_negative() const noexcept {
	return sign == -1;
}

LongNumber LongNumber::abs() const {
	LongNumber result(*this);
	result.sign = 1;
	return result;
}
LongNumber LongNumber::operator - () const {
	LongNumber result(*this);
	result.sign = -result.sign;
	return result;
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const noexcept {
	int len = 0;
	int start = 0;
	if (str[0] == '-') {
		start = 1;
	}
	while (str[start + len] != '\0') {
		len++;
	}
	return len;
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace pve {
	std::ostream& operator << (std::ostream& os, const LongNumber& x) {
		if (x.sign == -1) {
			os << '-';
		}
		for (int i = x.length - 1;i >= 0;i--) {
			os << x.numbers[i];
		}
		return os;
	}
}