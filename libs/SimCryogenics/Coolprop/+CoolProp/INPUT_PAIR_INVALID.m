function v = INPUT_PAIR_INVALID()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 94);
  end
  v = vInitialized;
end
