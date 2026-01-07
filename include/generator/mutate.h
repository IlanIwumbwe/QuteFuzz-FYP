#ifndef MUTATE_H
#define MUTATE_H

#include <node.h>
#include <variable.h>

class Mutation_rule {
    public:
        Mutation_rule(){}

        virtual bool match(const std::shared_ptr<Node> stmts) = 0;

        virtual void apply(std::shared_ptr<Node>& stmts) = 0;

    protected:
        std::vector<std::shared_ptr<Node>*> slots;
};

class X_HSSH : public Mutation_rule {
    public:
        X_HSSH():
            Mutation_rule()
        {}

        bool match(const std::shared_ptr<Node> compound_stmts);

        void apply(std::shared_ptr<Node>& compound_stmts);

    private:
};

#endif
