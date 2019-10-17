#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class lineType
{
public:
  void setLine(double, double, double);
  //Function to set the line.

  void equation() const;

  double getXCoefficient() const;
  double getYCoefficient() const;
  double getConstantTerm() const;

  void setXCoefficient(double coeff);
  void setYCoefficient(double coeff);
  void setConstantTerm(double c);

  double slope() const;
  // return slope

  double yIntercept() const;

  bool verticalLine() const;
  bool horizontalLine() const;

  bool equalLines(lineType otherLine) const;
  //Returns true of both lines are the same.

  bool parallel(lineType otherLine) const;
  //Function to determine if this line is parallel to otherLine.

  bool perpendicular(lineType otherLine) const;
  //Function to determine if this line is perperdicular to otherLine.

  void pointOfIntersection(lineType otherLine);
  //If lines intersect, then this function finds the point
  //of intersection.

  lineType(double, double, double);
  //Constructor

private:
  double xCoeff;
  double yCoeff;
  double constTerm;
  bool hasSlope;
};

void lineType::setLine(double x, double y, double c) {}

void lineType::equation() const
{
  cout << xCoeff << "+" << yCoeff << "=" << constTerm;
}

double lineType::getXCoefficient() const
{
  return xCoeff;
}

double lineType::getYCoefficient() const
{
  return yCoeff;
}

double lineType::getConstantTerm() const
{
  return constTerm;
}

void lineType::setXCoefficient(double coeff)
{
  xCoeff = coeff;
}

void lineType::setYCoefficient(double coeff)
{
  yCoeff = coeff;
}

void lineType::setConstantTerm(double c)
{
  constTerm = c;
}

double lineType::slope() const
{
  if (xCoeff >= 0)
  {
    double slope = -xCoeff / yCoeff;
    return slope;
  }
  else
  {
    double slope = fabs(xCoeff) / yCoeff;
    return slope;
  }
}

double lineType::yIntercept() const
{
  return constTerm / yCoeff;
}

bool lineType::verticalLine() const
{
  if (yCoeff == 0)
  {
    return true;
  }

  return false;
}

bool lineType::horizontalLine() const
{
  if (xCoeff == 0)
  {
    return true;
  }

  return false;
}

bool lineType::parallel(lineType otherLine) const
{
  if (this->slope() == otherLine.slope())
  {
    return true;
  }

  return false;
}

bool lineType::perpendicular(lineType otherLine) const
{
  if ((this->verticalLine() && otherLine.horizontalLine()) || (this->horizontalLine() && otherLine.verticalLine()))
  {
    return true;
  }

  return false;
}

bool lineType::equalLines(lineType otherLine) const
{
  if ((this->xCoeff == otherLine.xCoeff) && (this->yCoeff == otherLine.yCoeff) && (this->constTerm == otherLine.constTerm))
  {
    return true;
  }

  return false;
}

void lineType::pointOfIntersection(lineType otherLine)
{
  double y1 = this->yIntercept();
  double m1 = this->slope();

  double y2 = otherLine.yIntercept();
  double m2 = otherLine.slope();

  double x = floor((y2 - y1) / (m1 - m2));
  double y = (this->slope() * x) + y1;

  cout << "Point of intersection: "
       << "(" << x << "," << y << ")";
}

lineType::lineType(double A, double B, double C)
{
  xCoeff = A;
  yCoeff = B;
  constTerm = C;
}