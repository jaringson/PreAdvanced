#include "Relation.h"


Relation::Relation(Predicate scheme_var)
{
	scheme = scheme_var;
	name = scheme_var.name;
}
Relation::Relation()
{

}

Relation::~Relation()
{
}
