#include <iostream>
#include <ctime>
#include <cmath>

class Fighter
{
    private:
        int health_points, force_points, defence_points, agility_points, critical_points, points;
        double health;

        double force()
        {
            return 1+ this->force_points;
        }

        bool critical()
        {
                double critical_threshold = 1 / ( 1+pow( critical_points / 4.0, 4) );
                double normalized_random = rand() / static_cast<double>(RAND_MAX);

                return (normalized_random > critical_threshold);
        }

        double defence()
        {
            return 1/(1+pow(this->defence_points/4, 4));
        }

        bool agility()
        {
                double critical_threshold = 1 / ( 1+pow (agility_points / 4.0, 4) );
                double normalized_random = rand() / static_cast<double>(RAND_MAX);

                return (normalized_random > critical_threshold);
        }


    public:
        Fighter()
        {
            health = 100;
            health_points = force_points = critical_points = defence_points = agility_points = 0;
            points = 10;
        }

        Fighter(int health_points, int force_points, int critical_points, int defence_points, int agility_points)
        {
            this->health_points=health_points;
            this->force_points=force_points;
            this->critical_points=critical_points;
            this->defence_points=defence_points;
            this->agility_points=agility_points;
            this->health=100+(this->health_points*100);
            points = 0;
        }

        void set_points(short i)
        {
            this->points = i;
        }
        int get_points()
        {
            return this->points;
        }
        int get_health_points()
        {
            return this->health_points;
        }
        int get_force_points()
        {
            return this->force_points;
        }
        int get_defence_points()
        {
            return this->defence_points;
        }
        int get_agility_points()
        {
            return this->agility_points;
        }
        int get_critical_points()
        {
            return this->critical_points;
        }

        bool add_health_points(int points)
        {
            if ( (this->points>=points) && (points > 0) )
            {
                this->health_points += points;
                this->points -= points;
                return true;
            }
            else
                return false;
        }

        bool add_force_points(int points)
        {
            if ( (this->points>=points) && (points > 0) )
            {
                this->force_points += points;
                this->points -= points;
                return true;
            }
            else
                return false;
        }

        bool add_defence_points(int points)
        {
            if ( (this->points>=points) && (points > 0) )
            {
                this->defence_points += points;
                this->points -= points;
                return true;
            }
            else
                return false;
        }

        bool add_agility_points(int points)
        {
            if ( (this->points>=points) && (points > 0) )
            {
                this->agility_points += points;
                this->points -= points;
                return true;
            }
            else
                return false;
        }

        bool add_critical_points(int points)
        {
            if ( (this->points>=points) && (points > 0) )
            {
                this->critical_points += points;
                this->points -= points;
                return true;
            }
            else
                return false;
        }

        double attack()
        {
            return ( this->force()*(1+this->critical()) );
        }

        double damage(double dmg)
        {
            double real_damage = (1-this->agility()) * this->defence() * dmg;
            this->health -= real_damage;

            return real_damage;
        }

        bool is_dead()
        {
            if(this->health<=0)
                return true;
            else
                return false;
        }
};



Fighter create_fighter()
{
    Fighter player_fighter;
    short health_points = 0, force_points = 0, critical_points = 0, defence_points = 0, agility_points = 0;
    short choice, quantity;
    while ( true )
    {
        system("cls");
        std::cout<<"To exit the create fighter menu, enter -1 -1.\n"
                 <<"Current fighter options: \n"
                 <<"Health points: "<<health_points<<'\n'
                 <<"Force points: "<<force_points<<'\n'
                 <<"Defence points: "<<defence_points<<'\n'
                 <<"Agility points: "<<agility_points<<'\n'
                 <<"Critical points: "<<critical_points<<'\n'
                 <<"Choose what you want to add: \n"
                 <<"1-health points, 2-force points, 3-defence points, 4-agility points, 5-critical points.\n";
        std::cin>>choice;
        std::cout<<"Enter the quantity of points added: ";
        std::cin>>quantity;

       if ( (choice == -1) && (quantity == -1) )
           break;

       switch (choice) {
        case 1:
            if (health_points + quantity < 0)
            {
                std::cout<<"Parameter cannot be negative!\n";
                system("pause");
            }
            else
                health_points += quantity;
            break;
        case 2:
           if (force_points + quantity < 0)
           {
               std::cout<<"Parameter cannot be negative!\n";
               system("pause");
           }
           else
                force_points += quantity;
           break;
        case 3:
           if (defence_points + quantity < 0)
           {
               std::cout<<"Parameter cannot be negative!\n";
               system("pause");
           }
           else
               defence_points += quantity;
           break;
        case 4:
           if (agility_points + quantity < 0)
           {
               std::cout<<"Parameter cannot be negative!\n";
               system("pause");
           }
           else
               agility_points += quantity;
           break;
        case 5:
           if (critical_points + quantity < 0)
           {
               std::cout<<"Parameter cannot be negative!\n";
               system("pause");
           }
           else
               critical_points += quantity;
           break;
        default:
            std::cout<<"Invalid fighter parameter!\n";
            system("pause");
            break;
        }
    }

    player_fighter = Fighter(health_points, force_points, critical_points, defence_points, agility_points);
    return player_fighter;
}

Fighter random_fighter()
{
    Fighter random_fighter;
    short i, random;

    while (random_fighter.get_points() > 0)
    {
        i = rand() % (random_fighter.get_points() + 1);

        random = rand() %5;
        switch (random) {
        case 0:
           random_fighter.add_health_points(i);
           break;
        case 1:
           random_fighter.add_force_points(i);
           break;
        case 2:
           random_fighter.add_defence_points(i);
           break;
        case 3:
           random_fighter.add_agility_points(i);
           break;
        case 4:
           random_fighter.add_critical_points(i);
           break;
        default:
           std::cout<<"Error in random_fighter, random\n";
           break;
        }
    }

    return random_fighter;
}

void fight(Fighter fighter1, std::string name1, Fighter fighter2, std::string name2)
{
    bool is_turn_first = true;
    while ( (!fighter1.is_dead()) && (!fighter2.is_dead()) )
    {
        if (is_turn_first)
        {
            double received = fighter2.damage(fighter1.attack());

            std::cout << name2 << " took " << received << " damage\n";
        }
        else
        {
            double received = fighter1.damage(fighter2.attack());

            std::cout << name1 << " took " << received << " damage\n";
        }

        is_turn_first = !is_turn_first;
    }

    if ( fighter1.is_dead() )
        std::cout << '\n' << name2;
    else
        std::cout << '\n' << name1;

    std::cout << " win!\n";
}


int main()
{

    srand(time(NULL));

    short mode;
    std::cout<<"1 - PvP, 2 - PvB, 3 - PvB\n"
             <<"Choose a game mode: ";
    std::cin>>mode;

    Fighter fighter1, fighter2;
    std::string name1, name2;

    switch (mode) {
    case 1:
        fighter1 = create_fighter();
        std::cout<<"Player1, enter fighter name: ";
        std::cin>>name1;

        fighter2 = create_fighter();
        std::cout<<"Player2, enter fighter name: ";
        std::cin>>name2;
        break;
    case 2:
        fighter1 = create_fighter();
        std::cout<<"Player1, enter fighter name: ";
        std::cin>>name1;

        fighter2 = random_fighter();
        name2 = "Bot";
        break;
    case 3:
        fighter1 = random_fighter();
        name1 = "Bot1";

        fighter2 = random_fighter();
        name2 = "Bot2";
        break;
    default:
        std::cout<<"Wrong mode!\n";
        break;
    }

    fight(fighter1, name1, fighter2, name2);
    system("pause");
    return 0;


}
