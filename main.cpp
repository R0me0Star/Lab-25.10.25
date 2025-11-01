#include <iostream>

const unsigned MAX_U = 4294967295u; // Overflow constant for unsigned

bool isPyth(unsigned a, unsigned b, unsigned c) {
  if ((a != 0 && a > MAX_U / a) || // Overflow check
				(b != 0 && b > MAX_U / b) ||
				(c != 0 && c > MAX_U / c)) {
				throw 2; // Error 2 throw from function
		}
		bool p = a == b * b + c * c;
		p = p || b * b == a * a + c * c;
		p = p || c * c == a * a + b * b;
		return p;
}

int main() {
		using u_t = unsigned;
		u_t a = 0, b = 0, c = 0;
		std::cin >> a >> b;
		std::size_t count = 0;

		while (std::cin >> c) {
				try {
						count += isPyth(a, b, c) ? 1 : 0;
				}
				catch (int code) { // Catching error 2 from function
						std::cerr << "Overflow error\n";
						return 2;
				}
				a = b;
				b = c;
		}
		if (std::cin.eof()) {
				std::cout << count;
				std::cout << "\n";
		}
		else if (std::cin.fail()) {
				std::cerr << "Input error\n";
				return 1;
		}
}