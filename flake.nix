{
  description = "Flake for building arduino uno programs";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/23.11";

  outputs = {
    self,
    nixpkgs,
    flake-utils,
  }:
    flake-utils.lib.eachDefaultSystem
    (system: let
      pkgs = import nixpkgs {
        inherit system;
      };
    in {
      devShells.default = pkgs.mkShell {
        buildInputs = [
          pkgs.python311
          pkgs.python311Packages.grip
          pkgs.pkgsCross.avr.buildPackages.gcc8
          pkgs.pkgsCross.avr.buildPackages.avrdude
        ];

        shellHook = ''
        '';
      };
    });
}
