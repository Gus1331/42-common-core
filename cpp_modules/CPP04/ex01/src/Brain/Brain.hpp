# ifndef __BRAIN_H__
# define __BRAIN_H__

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Brain
{
    private:
        string ideas[100];
        int ideasCount;

    public:
        /* Constructors */
        Brain();
        Brain(const Brain &other);
        ~Brain();

        Brain &operator=(const Brain &other);

        /* Methods */
        void newIdea(string newIdea);

        /* Getters and Setters */
        string *getIdeas(void);
        void setIdeas(int ideas[100]);
        int getIdeasCount(void);
        void setIdeasCount(int ideasCount);
};

# endif
