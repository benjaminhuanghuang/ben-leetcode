import { defineConfig } from "vitest/config";

export default defineConfig({
  test: {
    globals: true, // allows using global test functions like describe, it, expect
    environment: "node", // or 'jsdom' for browser-like environment
    watch: false,
  },
});
