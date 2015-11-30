static int berlin_reset_xlate(
    struct reset_controller_dev *rcdev,
    const struct of_phandle_args *reset_spec)
{
    if (reset_spec->args_count != rcdev->of_reset_n_cells)
        return -EINVAL;
    offset = reset_spec->args[0];
    bit = reset_spec->args[1];
    if (bit >= BERLIN_MAX_RESETS)
        return -EINVAL;
    return (offset << 8) | bit;
}

