#ifndef OPSYSTEM_H
#define OPSYSTEM_H

class OpSystem
{
public:
    virtual int probability() const = 0;

};

class Windows: public OpSystem
{
    const static int infProb = 53;
public:
    int probability() const
    {
       return infProb;
    }
};

class MacOS: public OpSystem
{
    const static int infProb = 12;
public:
    int probability() const
    {
       return infProb;
    }
};

class Ubuntu: public OpSystem
{
    const static int infProb = 27;
public:
    int probability() const
    {
       return infProb;
    }
};

class VasyaOS: public OpSystem
{
    const static int infProb = 100;
public:
    int probability() const
    {
       return infProb;
    }
};
#endif // OPSYSTEM_H
