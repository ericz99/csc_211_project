#include "lineType.h"
#include <string>

using namespace std;

int main()
{
  // 6x + 2y = 4
  lineType firstLine(4, 2, 7);
  lineType secondLine(7, 4, 1);

  // check if firstline has vertical slope: PART (A)
  if (!firstLine.verticalLine())
  {
    cout << "First line: " << firstLine.slope() << " slope!";
  }
  else
  {
    cout << "Line has no slope! Slope is undefined!";
  }

  cout << endl;

  // # PART (B) check if both lines are equal
  if (firstLine.equalLines(secondLine))
  {
    cout << "Both lines are equal!";
  }
  else
  {
    cout << "Both lines are not equal";
  }

  cout << endl;

  // # PART (C)
  if (firstLine.parallel(secondLine))
  {
    cout << "Both lines are parallel!";
  }
  else
  {
    cout << "Both lines are not parallel!";
  }

  cout << endl;

  // # PART (D)
  if (firstLine.perpendicular(secondLine))
  {
    cout << "Both lines are perpendicular!";
  }
  else
  {
    cout << "Both lines are not perpendicular!";
  }

  cout << endl;

  // # PART (E)
  if (!firstLine.parallel(secondLine))
  {
    firstLine.pointOfIntersection(secondLine);
  }

  return 0;
}
