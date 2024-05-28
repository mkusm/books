-- below is the lua version of above
vim.api.nvim_set_keymap('n', ',.', ':term make %:r && echo "" && ./%:r<CR>', { noremap = true })
