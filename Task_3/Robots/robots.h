#ifndef ROBOTS_H
#define ROBOTS_H

class RobotsGraph
{
public:
    /**
     * @brief ableToDestroy check the ability of robots to be destroyed
     * @param source graph as the matrix
     * @param robots array of robots in vertexes
     * @param dim dimension of matrix (number of vertexes)
     * @return true? if robots can be destroyed
     */
    static bool ableToDestroy(bool **source, bool *robots, int dim);
};

#endif // ROBOTS_H
