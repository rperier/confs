struct reset_control_ops {
    int (*reset)(struct reset_controller_dev *rstc,
        unsigned long id);
    int (*assert)(struct reset_controller_dev *rstc,
        unsigned long id);
    int (*deassert)(struct reset_controller_dev *rstc,
        unsigned long id);
    int (*status)(struct reset_controller_dev *rstc,
        unsigned long id);
};

