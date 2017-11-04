class State {
  // delegate setting up all entities to this class
  public:
    State();
    ~State();
    Entity* getEntity(std::string name);
    void updateEntity(std::string name, Entity entity);
    Entity* getPlayer();
  private: 
    std::unordered_map<std::string, Entity*>* entities;
   
};