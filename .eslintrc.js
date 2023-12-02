/*
 * @Author: weisheng
 * @Date: 2023-03-14 16:06:21
 * @LastEditTime: 2023-03-28 16:52:32
 * @LastEditors: weisheng
 * @Description:
 * @FilePath: \wot-design-uni\.eslintrc.js
 * 记得注释
*/
module.exports = {
	root: true,
	env: {
		node: true,
	},
	globals: {
		// Ref sugar (take 2)
		$: "readonly",
		$$: "readonly",
		$ref: "readonly",
		$shallowRef: "readonly",
		$computed: "readonly",
		// index.d.ts
		// global.d.ts
		Fn: "readonly",
		PromiseFn: "readonly",
		RefType: "readonly",
		LabelValueOptions: "readonly",
		EmitType: "readonly",
		TargetContext: "readonly",
		ComponentElRef: "readonly",
		ComponentRef: "readonly",
		ElRef: "readonly",
		global: "readonly",
		ForDataType: "readonly",
		ComponentRoutes: "readonly",
		// script setup
		defineProps: "readonly",
		defineEmits: "readonly",
		defineExpose: "readonly",
		withDefaults: "readonly",
	},
	extends: [
		"eslint:recommended",
		"@vue/prettier",
		"@vue/typescript/recommended",
		"@vue/eslint-config-typescript",
	],
	parser: "vue-eslint-parser",
	parserOptions: {
		parser: "@typescript-eslint/parser",
		ecmaVersion: 2020,
		sourceType: "module",
		jsxPragma: "React",
		ecmaFeatures: {
			vue: true,
			jsx: true,
			tsx: true,
			astro: true,
			svelte: true,
		},
	},
	overrides: [
		{
			files: ["*.js", "*.ts", "*.vue", "*.jsx", "*.tsx", "*.astro", "*.svelte"],
			rules: {
				"no-undef": "off",
			},
		},
		{
			files: ["*.vue"],
			parser: "vue-eslint-parser",
			parserOptions: {
				parser: "@typescript-eslint/parser",
				extraFileExtensions: [".vue"],
				ecmaVersion: "latest",
				ecmaFeatures: {
					jsx: true,
					tsx: true,
				},
			},
			rules: {
				"no-undef": "off",
			},
		},
	],
	rules: {
    "no-debugger": "off",
		"vue/no-v-html": "off",
		"no-unused-vars": "off",
    "no-prototype-builtins": "off",
		"vue/html-self-closing": "off",
		"vue/comment-directive": "off",
		"vue/require-default-prop": "off",
		"vue/require-explicit-emits": "off",
		"vue/multi-word-component-names": "off",
		"@javascript-eslint/semi": "off",
		"@typescript-eslint/semi": "off",
		"@typescript-eslint/ban-types": "off",
		"@typescript-eslint/no-this-alias": "off",
		"@typescript-eslint/no-unused-vars": "off",
		"@typescript-eslint/ban-ts-comment": "off",
		"@typescript-eslint/no-explicit-any": "off",
		"@typescript-eslint/no-var-requires": "off",
		"@typescript-eslint/no-empty-function": "off",
		"@typescript-eslint/no-empty-interface": "off",
    "@typescript-eslint/no-inferrable-types": "off",
		"@typescript-eslint/no-non-null-assertion": "off",
		"@typescript-eslint/space-before-function-paren": "off",
		"@typescript-eslint/explicit-module-boundary-types": "off",
		"prettier/prettier": [
			"off",
			{
				endOfLine: "crlf",
			},
		],
	},
};
