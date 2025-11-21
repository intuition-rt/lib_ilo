{
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";

  outputs = {
    self,
    nixpkgs,
  }: let
    forAllSystems = function:
      nixpkgs.lib.genAttrs [
        "x86_64-linux"
        "aarch64-linux"
        "aarch64-darwin"
      ] (system: function nixpkgs.legacyPackages.${system});
  in {
    devShells = forAllSystems (pkgs: {
      default = pkgs.mkShell {
        hardeningDisable = ["fortify"];

        packages = with pkgs; [
          gcc
          platformio
          clang-tools
          scom
          compiledb
        ];
      };
    });

    formatter = forAllSystems (pkgs: pkgs.alejandra);
  };
}
