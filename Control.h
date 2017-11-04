class Control {
  public: 
    ~Control();
    Control(Entity* controlled);
    void update();
  private:
    Entity* controlled;
};
