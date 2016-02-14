#include <exception>

class EmptyPopException : public std::exception {};
class NotFoundException : public std::exception {};
class OutOfBoundsException : public std::exception {};
