#ifndef FEETINCHES_H
#define FEETINCHES_H

class FeetInches
{
private:
	int _inches;
public:
	FeetInches(int feet, int inches) { _inches = inches + (feet * 12); };
	FeetInches(const FeetInches &fi) { _inches = fi.getAsInches(); };
	int getFeet() const { return _inches / 12; };
	int getInches() const { return _inches % 12; };
	int getAsInches() const { return _inches; };
	FeetInches multiply(const FeetInches &) const;
	FeetInches operator + (const FeetInches &);
	FeetInches operator - (const FeetInches &);
	FeetInches operator ++ ();    // Prefix
	FeetInches operator ++ (int); // Postfix
	FeetInches operator -- ();    // Prefix
	FeetInches operator -- (int); // Postfix
	bool operator > (const FeetInches &);
	bool operator < (const FeetInches &);
	bool operator == (const FeetInches &);
	bool operator >= (const FeetInches &);
	bool operator <= (const FeetInches &);
	bool operator != (const FeetInches &);
};

#endif
