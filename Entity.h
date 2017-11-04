class Entity {
  public:
    Entity();
    ~Entity();
    virtual void move() {};
  private: 
    int xPos, yPos;

};
