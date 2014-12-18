#ifndef COMMANDFIELD_H
#define COMMANDFIELD_H

#include "field.h"

class CommandField {
public:
    virtual ~CommandField();
    virtual void execute(int x, int y) = 0;
protected:
    CommandField(Field* _field): field(_field) {}
    Field* field;
};

class CommandFieldCheck: public CommandField {
public:
    CommandFieldCheck(Field* field): CommandField(field) {}
    void execute(int x, int y) {
        //field->check()
    }
};

class CommandFieldDestroy: public CommandField {
public:
    CommandFieldDestroy(Field* field): CommandField(field) {}
    void execute(int x, int y) {
        //field->destroy();
    }
};

#endif // COMMANDFIELD_H
