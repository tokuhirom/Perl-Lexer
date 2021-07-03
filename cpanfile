requires 'perl', '5.010000';
requires 'parent';

on 'configure' => sub {
    require 'Module::Build::Tiny', '0.035';
};

on 'test' => sub {
    requires 'Test::More', '0.98';
};

