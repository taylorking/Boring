class Control {
  public: 
    ~Control();
    Control(Entity* controlled);
    void update();
};
