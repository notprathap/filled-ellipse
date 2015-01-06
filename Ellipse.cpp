#include "Ellipse.h"

namespace Ellipse{
    long Ellipse::twoASquare()
    {
        return 2 * xRadius * xRadius;
    }

    long Ellipse::twoBSquare()
    {
        return 2 * yRadius * yRadius;
    }

    Ellipse::Ellipse(long a, long b, long xOffset, long yOffset)
    {
        xRadius = a;
        yRadius = b;
        cx = xOffset;
        cy = yOffset;
    }

    Ellipse::~Ellipse()
    {

    }

    std::vector<LVertexPos2D> Ellipse::getFirstSetOfPoints()
    {
        x = xRadius;
        y = 0;
        xChange = yRadius * yRadius * (1 - 2 * xRadius);
        yChange = xRadius * xRadius;
        ellipseError = 0;
        stoppingX = twoBSquare() * xRadius;
        stoppingY = 0;

        std::vector<LVertexPos2D> points;

        while (stoppingX >= stoppingY){
            // fill up points
            fillUpPoints(points, x, y);

            // increment y
            y++;

            // increment stoppingY
            stoppingY += twoASquare();

            // increment ellipseError
            ellipseError += yChange;

            // increment yChange
            yChange += twoASquare();

            if ((2 * ellipseError + xChange) > 0){
                // decrement x
                x--;

                // decrement stoppingX
                stoppingX -= twoBSquare();

                // increment ellipseError
                ellipseError += xChange;

                // increment xChange
                xChange += twoBSquare();
            }
        }

        return points;

    }

    std::vector<LVertexPos2D> Ellipse::getSecondSetOfPoints()
    {
        x = 0;
        y = yRadius;
        xChange = yRadius * yRadius;
        yChange = xRadius * xRadius * (1 - 2 * yRadius);
        ellipseError = 0;
        stoppingX = 0;
        stoppingY = twoASquare() * yRadius;

        std::vector<LVertexPos2D> points;

        while (stoppingX <= stoppingY){
            // fill up points
            fillUpPoints(points, x, y);

            // increment x
            x++;

            // increment stoppingX
            stoppingX += twoBSquare();

            // increment ellipseError
            ellipseError += xChange;

            // increment xChange
            xChange += twoBSquare();

            if ((2 * ellipseError + yChange) > 0){
                // decrement y
                y--;

                // decrement stoppingY
                stoppingY -= twoASquare();

                // increment ellipseError
                ellipseError += yChange;

                // increment yChange
                yChange += twoASquare();
            }
        }

        return points;

    }

    void Ellipse::fillUpPoints(std::vector<LVertexPos2D>& points, long x, long y)
    {
        // point in quadrant 1
        LVertexPos2D pq1;
        pq1.x = cx + x;
        pq1.y = cy + y;
        points.push_back(pq1);

        // point in quadrant 2
        LVertexPos2D pq2;
        pq2.x = cx - x;
        pq2.y = cy + y;
        points.push_back(pq2);

        // point in quadrant 3
        LVertexPos2D pq3;
        pq3.x = cx - x;
        pq3.y = cy - y;
        points.push_back(pq3);

        // point in quadrant 4
        LVertexPos2D pq4;
        pq4.x = cx + x;
        pq4.y = cy - y;
        points.push_back(pq4);
    }

}
