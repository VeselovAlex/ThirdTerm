#ifndef OPSYSTEM_H
#define OPSYSTEM_H

class OpSystem
{
    static const int infProb;
public:
    int probability() const
    {
       return infProb;
    }
};

class Windows: public OpSystem
{
    const static int infProb = 53;
};

class MacOS: public OpSystem
{
    const static int infProb = 12;
};

class Ubuntu: public OpSystem
{
    const static int infProb = 27;
};

#endif // OPSYSTEM_H
