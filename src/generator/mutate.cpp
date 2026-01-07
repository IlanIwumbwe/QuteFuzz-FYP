#include <mutate.h>
#include <cassert>

bool X_HSSH::match(const std::shared_ptr<Node> compound_stmts){
    
    std::vector<std::shared_ptr<Node>*> visited_slots;
    std::shared_ptr<Node>* maybe_compound_stmt = compound_stmts->find_slot(COMPOUND_STMT, visited_slots);

    std::cout << "============================" << std::endl;
    std::cout << *compound_stmts << std::endl;

    bool matches = false;

    while(maybe_compound_stmt != nullptr){
        std::shared_ptr<Node> compound_stmt = *maybe_compound_stmt;

        assert(compound_stmt->get_num_children() == 1);

        if((*compound_stmt == QUBIT_OP) && (compound_stmt->find(X) != nullptr)){
            slots.push_back(maybe_compound_stmt);
            std::cout << "matches" << std::endl;
            matches = true;
        }

        maybe_compound_stmt = compound_stmts->find_slot(COMPOUND_STMT, visited_slots);
    }
    std::cout << "============================" << std::endl;

    return matches;
}

void X_HSSH::apply(std::shared_ptr<Node>& compound_stmts){
    assert(slots.size() == 1); // one X gate slot
    
    std::shared_ptr<Node>* compound_stmt = slots[0];
    std::shared_ptr<Node> qubit = (*compound_stmt)->find(QUBIT);

    std::cout << *qubit << std::endl;
}

