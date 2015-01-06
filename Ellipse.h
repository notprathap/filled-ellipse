#include "LVertexPos2D.h"
#include <vector>

namespace Ellipse{
	class Ellipse
	{
	private:
		long x;
		long y;
		long cx;
		long cy;
		long xRadius;
		long yRadius;
		long xChange;
		long yChange;
		long ellipseError;
		long stoppingX;
		long stoppingY;

		long twoASquare();
		long twoBSquare();
		void fillUpPoints(std::vector<LVertexPos2D>& points, long x, long y);
		
	public:
		Ellipse(long xRadius, long yRadius, long cx, long cy);
		~Ellipse();
		std::vector<LVertexPos2D> getFirstSetOfPoints(); // When tangent line slope is > -1
		std::vector<LVertexPos2D> getSecondSetOfPoints(); // When tangent line slope is < -1
	};
}

