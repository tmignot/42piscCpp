#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy(void) : targets(new CentralBureaucracy::String()), waiting(NULL)
{
    int        i;

    i = 0;
    while (i < 20)
    {
        this->offices[i] = NULL;
        i++;
    }
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &bureau)
{
    *this = bureau;
}

CentralBureaucracy::~CentralBureaucracy(void)
{
    int        i;

    i = 0;
    while (i < 20 && this->offices[i])
    {
        delete this->offices[i];
        this->offices[i] = NULL;
        i++;
    }
    this->targets->deleteAll();
    delete this->targets;
}

CentralBureaucracy                    &CentralBureaucracy::operator=(CentralBureaucracy const &bureau)
{
    for (int i = 0; i < 20; i++)
        this->offices[i] = bureau.offices[i];
    this->targets = bureau.targets;
    return (*this);
}

void                                CentralBureaucracy::hire(Bureaucrat &bureaucrat)
{
    int            i;
    Intern           *intern;

    if (this->waiting)
    {
        std::cout << *(this->waiting) << std::endl;
        i = 0;
        while (i < 20 && this->offices[i])
            i++;
        if (i < 20)
        {
            intern = new Intern();
            this->offices[i] = new OfficeBlock(intern, this->waiting, &bureaucrat);
            this->waiting = NULL;
        }
        else
            std::cout << "Sorry we are not hiring at the moment" << std::endl;
    }
    else
        this->waiting = &bureaucrat;
}

void                                CentralBureaucracy::queueUp(std::string target)
{
    this->targets->add(target);
}

void                                CentralBureaucracy::doBureaucracy(void)
{
    int        i;
    std::string        requests[] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

    if (this->offices[0])
    {
        i = 0;
        while (this->targets->next)
        {
            if (!this->offices[i])
                i = 0;
            this->offices[i]->doBureaucracy(requests[i % 3], *(this->targets->pop()));
            i++;
        }
    }
    else
    {
        std::cout << "Sorry but we are short of staff at the moment" << std::endl;
    }
}

CentralBureaucracy::String::String(void) : next(NULL), last(this){}
CentralBureaucracy::String::String(std::string value) : value(value), next(NULL), last(this){}
CentralBureaucracy::String::String(CentralBureaucracy::String const &string)
{
    *this = string;
}
CentralBureaucracy::String::~String(void){}
CentralBureaucracy::String            &CentralBureaucracy::String::operator=(CentralBureaucracy::String const &string)
{
    this->value.assign(string.value);
    this->next = next;
    this->last = last;
    return (*this);
}

void                                   CentralBureaucracy::String::add(std::string value)
{
    CentralBureaucracy::String            *string;

    string = new String(value);
    this->last->next = string;
    this->last = string;
}

void                                    CentralBureaucracy::String::deleteAll(void)
{
    CentralBureaucracy::String            *tmp1;
    CentralBureaucracy::String            *tmp2;

    tmp1 = this->next;
    while (tmp1)
    {
        tmp2 = this->next;
        delete tmp1;
        tmp1 = tmp2;
    }
}

std::string                            *CentralBureaucracy::String::pop(void)
{
    std::string        *ret = NULL;
    CentralBureaucracy::String            *tmp;

    tmp = this->next;
    if (tmp)
    {
        ret = new std::string(tmp->value);
        this->next = tmp->next;
        if (!this->next)
            this->last = this;
        delete tmp;
    }
    return ret;
}
