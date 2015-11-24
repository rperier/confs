struct reset_controller_dev {
    struct reset_control_ops *ops;
    struct module *owner;
    struct device_node *of_node;
    unsigned int nr_resets;
    /* Optional fields */
    int of_reset_n_cells;
    int (*of_xlate)(struct reset_controller_dev *rcdev,
        const struct of_phandle_args *reset_spec);
};
